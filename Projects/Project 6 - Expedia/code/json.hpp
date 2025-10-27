/**
 * @file json.hpp
 * @brief Simple JSON parser / serializer (header-only)
 *
 * A lightweight, header-only JSON library used by the Square payment adapter.
 * Supports:
 * - Parsing JSON strings (`JSON::Load`)
 * - Building JSON objects / arrays (`JSON::Make`, `Array()`, `Object()`)
 * - Type-safe access (`ToString()`, `ToInt()`, `ToFloat()`, `ToBool()`)
 * - Pretty printing (`dump()`)
 *
 * @note This file is **required** for `expedia_payments_api.h` when using Square.
 */

#pragma once

#include <cstdint>
#include <cmath>
#include <cctype>
#include <string>
#include <deque>
#include <map>
#include <type_traits>
#include <initializer_list>
#include <ostream>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace json
{

    using std::deque;
    using std::enable_if;
    using std::initializer_list;
    using std::is_convertible;
    using std::is_floating_point;
    using std::is_integral;
    using std::is_same;
    using std::map;
    using std::string;

    /* -------------------------------------------------------------------------- */
    /* Helper: JSON string escaping                                               */
    /* -------------------------------------------------------------------------- */
    namespace
    {
        string json_escape(const string &str)
        {
            string output;
            for (char c : str)
            {
                switch (c)
                {
                case '\"':
                    output += "\\\"";
                    break;
                case '\\':
                    output += "\\\\";
                    break;
                case '\b':
                    output += "\\b";
                    break;
                case '\f':
                    output += "\\f";
                    break;
                case '\n':
                    output += "\\n";
                    break;
                case '\r':
                    output += "\\r";
                    break;
                case '\t':
                    output += "\\t";
                    break;
                default:
                    output += c;
                    break;
                }
            }
            return output;
        }
    }

    /* -------------------------------------------------------------------------- */
    /* Core JSON class                                                            */
    /* -------------------------------------------------------------------------- */
    class JSON
    {
        union BackingData
        {
            BackingData(double d) : Float(d) {}
            BackingData(long l) : Int(l) {}
            BackingData(bool b) : Bool(b) {}
            BackingData(string s) : String(new string(std::move(s))) {}
            BackingData() : Int(0) {}

            deque<JSON> *List;
            map<string, JSON> *Map;
            string *String;
            double Float;
            long Int;
            bool Bool;
        } Internal;

    public:
        /** @brief JSON value type */
        enum class Class
        {
            Null,     ///< `null`
            Object,   ///< `{ ... }`
            Array,    ///< `[ ... ]`
            String,   ///< `"..."` (escaped)
            Floating, ///< `double`
            Integral, ///< `long`
            Boolean   ///< `true` / `false`
        };

        /* ------------------------------------------------------------------ */
        /* Iterator wrappers (allow range-based for loops)                    */
        /* ------------------------------------------------------------------ */
        template <typename Container>
        class JSONWrapper
        {
            Container *object;

        public:
            JSONWrapper(Container *val) : object(val) {}
            JSONWrapper(std::nullptr_t) : object(nullptr) {}

            auto begin() -> decltype(object->begin()) { return object ? object->begin() : decltype(object->begin())(); }
            auto end() -> decltype(object->end()) { return object ? object->end() : decltype(object->end())(); }
            auto begin() const -> decltype(object->begin()) { return object ? object->begin() : decltype(object->begin())(); }
            auto end() const -> decltype(object->end()) { return object ? object->end() : decltype(object->end())(); }
        };

        template <typename Container>
        class JSONConstWrapper
        {
            const Container *object;

        public:
            JSONConstWrapper(const Container *val) : object(val) {}
            JSONConstWrapper(std::nullptr_t) : object(nullptr) {}

            auto begin() const -> decltype(object->begin()) { return object ? object->begin() : decltype(object->begin())(); }
            auto end() const -> decltype(object->end()) { return object ? object->end() : decltype(object->end())(); }
        };

        /* ------------------------------------------------------------------ */
        /* Constructors / destructors                                         */
        /* ------------------------------------------------------------------ */
        JSON() : Internal(), Type(Class::Null) {}

        JSON(initializer_list<JSON> list) : JSON()
        {
            SetType(Class::Object);
            for (auto i = list.begin(), e = list.end(); i != e; ++i, ++i)
                operator[](i->ToString()) = *std::next(i);
        }

        JSON(JSON &&other) noexcept
            : Internal(other.Internal), Type(other.Type)
        {
            other.Type = Class::Null;
            other.Internal.Map = nullptr;
        }

        JSON &operator=(JSON &&other) noexcept
        {
            ClearInternal();
            Internal = other.Internal;
            Type = other.Type;
            other.Internal.Map = nullptr;
            other.Type = Class::Null;
            return *this;
        }

        JSON(const JSON &other) { copy_from(other); }
        JSON &operator=(const JSON &other)
        {
            if (this != &other)
            {
                ClearInternal();
                copy_from(other);
            }
            return *this;
        }

        ~JSON() { ClearInternal(); }

        /* ------------------------------------------------------------------ */
        /* Implicit constructors for primitive types                           */
        /* ------------------------------------------------------------------ */
        template <typename T>
        JSON(T b, typename enable_if<is_same<T, bool>::value>::type * = nullptr)
            : JSON()
        {
            SetType(Class::Boolean);
            Internal.Bool = b;
        }

        template <typename T>
        JSON(T i, typename enable_if<is_integral<T>::value && !is_same<T, bool>::value>::type * = nullptr)
            : JSON()
        {
            SetType(Class::Integral);
            Internal.Int = static_cast<long>(i);
        }

        template <typename T>
        JSON(T f, typename enable_if<is_floating_point<T>::value>::type * = nullptr)
            : JSON()
        {
            SetType(Class::Floating);
            Internal.Float = static_cast<double>(f);
        }

        template <typename T>
        JSON(T s, typename enable_if<is_convertible<T, string>::value>::type * = nullptr)
            : JSON()
        {
            SetType(Class::String);
            Internal.String = new string(s);
        }

        JSON(std::nullptr_t) : JSON() { SetType(Class::Null); }

        /* ------------------------------------------------------------------ */
        /* Factory helpers                                                    */
        /* ------------------------------------------------------------------ */
        static JSON Make(Class type)
        {
            JSON ret;
            ret.SetType(type);
            return ret;
        }

        static JSON Load(const string &str);

        /* ------------------------------------------------------------------ */
        /* Array / object building helpers                                    */
        /* ------------------------------------------------------------------ */
        template <typename T>
        void append(T arg)
        {
            SetType(Class::Array);
            Internal.List->emplace_back(arg);
        }

        template <typename T, typename... U>
        void append(T arg, U... args)
        {
            append(arg);
            append(args...);
        }

        /* ------------------------------------------------------------------ */
        /* Assignment operators                                               */
        /* ------------------------------------------------------------------ */
        template <typename T>
        typename enable_if<is_same<T, bool>::value, JSON &>::type operator=(T b)
        {
            SetType(Class::Boolean);
            Internal.Bool = b;
            return *this;
        }

        template <typename T>
        typename enable_if<is_integral<T>::value && !is_same<T, bool>::value, JSON &>::type operator=(T i)
        {
            SetType(Class::Integral);
            Internal.Int = static_cast<long>(i);
            return *this;
        }

        template <typename T>
        typename enable_if<is_floating_point<T>::value, JSON &>::type operator=(T f)
        {
            SetType(Class::Floating);
            Internal.Float = static_cast<double>(f);
            return *this;
        }

        template <typename T>
        typename enable_if<is_convertible<T, string>::value, JSON &>::type operator=(T s)
        {
            SetType(Class::String);
            *Internal.String = string(s);
            return *this;
        }

        /* ------------------------------------------------------------------ */
        /* Subscript operators (object / array)                               */
        /* ------------------------------------------------------------------ */
        JSON &operator[](const string &key)
        {
            SetType(Class::Object);
            return (*Internal.Map)[key];
        }

        JSON &operator[](unsigned index)
        {
            SetType(Class::Array);
            if (index >= Internal.List->size())
                Internal.List->resize(index + 1);
            return (*Internal.List)[index];
        }

        JSON &at(const string &key) { return operator[](key); }
        const JSON &at(const string &key) const { return Internal.Map->at(key); }
        JSON &at(unsigned index) { return operator[](index); }
        const JSON &at(unsigned index) const { return Internal.List->at(index); }

        /* ------------------------------------------------------------------ */
        /* Size / type queries                                                */
        /* ------------------------------------------------------------------ */
        int length() const { return (Type == Class::Array) ? static_cast<int>(Internal.List->size()) : -1; }
        bool hasKey(const string &key) const { return (Type == Class::Object) && Internal.Map->find(key) != Internal.Map->end(); }
        int size() const
        {
            if (Type == Class::Object)
                return static_cast<int>(Internal.Map->size());
            if (Type == Class::Array)
                return static_cast<int>(Internal.List->size());
            return -1;
        }
        Class JSONType() const { return Type; }

        /* ------------------------------------------------------------------ */
        /* Type checks                                                        */
        /* ------------------------------------------------------------------ */
        bool IsNull() const { return Type == Class::Null; }

        /* ------------------------------------------------------------------ */
        /* Primitive extraction (with optional success flag)                  */
        /* ------------------------------------------------------------------ */
        string ToString() const
        {
            bool ok;
            return ToString(ok);
        }
        string ToString(bool &ok) const
        {
            ok = (Type == Class::String);
            return ok ? json_escape(*Internal.String) : "";
        }

        double ToFloat() const
        {
            bool ok;
            return ToFloat(ok);
        }
        double ToFloat(bool &ok) const
        {
            ok = (Type == Class::Floating);
            return ok ? Internal.Float : 0.0;
        }

        long ToInt() const
        {
            bool ok;
            return ToInt(ok);
        }
        long ToInt(bool &ok) const
        {
            ok = (Type == Class::Integral);
            return ok ? Internal.Int : 0L;
        }

        bool ToBool() const
        {
            bool ok;
            return ToBool(ok);
        }
        bool ToBool(bool &ok) const
        {
            ok = (Type == Class::Boolean);
            return ok ? Internal.Bool : false;
        }

        /* ------------------------------------------------------------------ */
        /* Range-based iteration helpers                                      */
        /* ------------------------------------------------------------------ */
        JSONWrapper<map<string, JSON>> ObjectRange()
        {
            return (Type == Class::Object) ? JSONWrapper<map<string, JSON>>(Internal.Map)
                                           : JSONWrapper<map<string, JSON>>(nullptr);
        }
        JSONWrapper<deque<JSON>> ArrayRange()
        {
            return (Type == Class::Array) ? JSONWrapper<deque<JSON>>(Internal.List)
                                          : JSONWrapper<deque<JSON>>(nullptr);
        }

        JSONConstWrapper<map<string, JSON>> ObjectRange() const
        {
            return (Type == Class::Object) ? JSONConstWrapper<map<string, JSON>>(Internal.Map)
                                           : JSONConstWrapper<map<string, JSON>>(nullptr);
        }
        JSONConstWrapper<deque<JSON>> ArrayRange() const
        {
            return (Type == Class::Array) ? JSONConstWrapper<deque<JSON>>(Internal.List)
                                          : JSONConstWrapper<deque<JSON>>(nullptr);
        }

        /* ------------------------------------------------------------------ */
        /* Pretty printing                                                    */
        /* ------------------------------------------------------------------ */
        string dump(int depth = 1, const string &tab = "  ") const
        {
            string pad(depth * tab.size(), ' ');
            switch (Type)
            {
            case Class::Null:
                return "null";
            case Class::Object:
            {
                string s = "{\n";
                bool first = true;
                for (const auto &p : *Internal.Map)
                {
                    if (!first)
                        s += ",\n";
                    s += pad + tab + "\"" + p.first + "\" : " + p.second.dump(depth + 1, tab);
                    first = false;
                }
                s += "\n" + pad + "}";
                return s;
            }
            case Class::Array:
            {
                string s = "[";
                bool first = true;
                for (const auto &v : *Internal.List)
                {
                    if (!first)
                        s += ", ";
                    s += v.dump(depth + 1, tab);
                    first = false;
                }
                s += "]";
                return s;
            }
            case Class::String:
                return "\"" + json_escape(*Internal.String) + "\"";
            case Class::Floating:
                return std::to_string(Internal.Float);
            case Class::Integral:
                return std::to_string(Internal.Int);
            case Class::Boolean:
                return Internal.Bool ? "true" : "false";
            default:
                return "";
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const JSON &json)
        {
            os << json.dump();
            return os;
        }

    private:
        void SetType(Class type)
        {
            if (type == Type)
                return;
            ClearInternal();
            switch (type)
            {
            case Class::Null:
                Internal.Map = nullptr;
                break;
            case Class::Object:
                Internal.Map = new map<string, JSON>();
                break;
            case Class::Array:
                Internal.List = new deque<JSON>();
                break;
            case Class::String:
                Internal.String = new string();
                break;
            case Class::Floating:
                Internal.Float = 0.0;
                break;
            case Class::Integral:
                Internal.Int = 0;
                break;
            case Class::Boolean:
                Internal.Bool = false;
                break;
            }
            Type = type;
        }

        void ClearInternal()
        {
            switch (Type)
            {
            case Class::Object:
                delete Internal.Map;
                break;
            case Class::Array:
                delete Internal.List;
                break;
            case Class::String:
                delete Internal.String;
                break;
            default:
                break;
            }
        }

        void copy_from(const JSON &other)
        {
            switch (other.Type)
            {
            case Class::Object:
                Internal.Map = new map<string, JSON>(other.Internal.Map->begin(),
                                                     other.Internal.Map->end());
                break;
            case Class::Array:
                Internal.List = new deque<JSON>(other.Internal.List->begin(),
                                                other.Internal.List->end());
                break;
            case Class::String:
                Internal.String = new string(*other.Internal.String);
                break;
            default:
                Internal = other.Internal;
                break;
            }
            Type = other.Type;
        }

        Class Type = Class::Null;
    };

    /* -------------------------------------------------------------------------- */
    /* Convenience factory functions                                              */
    /* -------------------------------------------------------------------------- */
    inline JSON Array() { return JSON::Make(JSON::Class::Array); }

    template <typename... T>
    inline JSON Array(T... args)
    {
        JSON arr = JSON::Make(JSON::Class::Array);
        arr.append(args...);
        return arr;
    }

    inline JSON Object() { return JSON::Make(JSON::Class::Object); }

    /* -------------------------------------------------------------------------- */
    /* Parser implementation (private to the namespace)                           */
    /* -------------------------------------------------------------------------- */
    namespace
    {
        JSON parse_next(const string &, size_t &);
        void consume_ws(const string &str, size_t &offset)
        {
            while (offset < str.size() && std::isspace(str[offset]))
                ++offset;
        }

        JSON parse_object(const string &str, size_t &offset)
        {
            JSON obj = JSON::Make(JSON::Class::Object);
            ++offset;
            consume_ws(str, offset);
            if (str[offset] == '}')
            {
                ++offset;
                return obj;
            }

            while (true)
            {
                JSON key = parse_next(str, offset);
                consume_ws(str, offset);
                if (str[offset] != ':')
                {
                    std::cerr << "Error: Object: Expected ':', found '" << str[offset] << "'\n";
                    break;
                }
                ++offset;
                consume_ws(str, offset);
                JSON val = parse_next(str, offset);
                obj[key.ToString()] = std::move(val);
                consume_ws(str, offset);
                if (str[offset] == ',')
                {
                    ++offset;
                    continue;
                }
                if (str[offset] == '}')
                {
                    ++offset;
                    break;
                }
                std::cerr << "Error: Object: Expected ',' or '}', found '" << str[offset] << "'\n";
                break;
            }
            return obj;
        }

        JSON parse_array(const string &str, size_t &offset)
        {
            JSON arr = JSON::Make(JSON::Class::Array);
            ++offset;
            consume_ws(str, offset);
            if (str[offset] == ']')
            {
                ++offset;
                return arr;
            }

            unsigned idx = 0;
            while (true)
            {
                arr[idx++] = parse_next(str, offset);
                consume_ws(str, offset);
                if (str[offset] == ',')
                {
                    ++offset;
                    continue;
                }
                if (str[offset] == ']')
                {
                    ++offset;
                    break;
                }
                std::cerr << "Error: Array: Expected ',' or ']', found '" << str[offset] << "'\n";
                break;
            }
            return arr;
        }

        JSON parse_string(const string &str, size_t &offset)
        {
            string val;
            for (char c = str[++offset]; c != '\"'; c = str[++offset])
            {
                if (c == '\\')
                {
                    switch (str[++offset])
                    {
                    case '\"':
                        val += '\"';
                        break;
                    case '\\':
                        val += '\\';
                        break;
                    case '/':
                        val += '/';
                        break;
                    case 'b':
                        val += '\b';
                        break;
                    case 'f':
                        val += '\f';
                        break;
                    case 'n':
                        val += '\n';
                        break;
                    case 'r':
                        val += '\r';
                        break;
                    case 't':
                        val += '\t';
                        break;
                    case 'u':
                    {
                        val += "\\u";
                        for (unsigned i = 0; i < 4; ++i)
                        {
                            char ch = str[offset + 1 + i];
                            if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
                                val += ch;
                            else
                            {
                                std::cerr << "Error: String: Bad unicode escape\n";
                                return JSON::Make(JSON::Class::String);
                            }
                        }
                        offset += 4;
                        break;
                    }
                    default:
                        val += '\\';
                        break;
                    }
                }
                else
                {
                    val += c;
                }
            }
            ++offset;
            JSON j;
            j = val;
            return j;
        }

        JSON parse_number(const string &str, size_t &offset)
        {
            string val, exp_str;
            char c;
            bool isDouble = false;
            long exp = 0;

            while (true)
            {
                c = str[offset++];
                if ((c == '-') || (c >= '0' && c <= '9'))
                    val += c;
                else if (c == '.')
                {
                    val += c;
                    isDouble = true;
                }
                else
                    break;
            }

            if (c == 'e' || c == 'E')
            {
                c = str[offset++];
                if (c == '-')
                {
                    exp_str += '-';
                    ++offset;
                }
                while (true)
                {
                    c = str[offset++];
                    if (c >= '0' && c <= '9')
                        exp_str += c;
                    else
                        break;
                }
                exp = std::stol(exp_str);
            }
            else if (!std::isspace(c) && c != ',' && c != ']' && c != '}')
            {
                std::cerr << "Error: Number: Unexpected '" << c << "'\n";
                return JSON::Make(JSON::Class::Null);
            }
            --offset;

            JSON num;
            if (isDouble)
                num = std::stod(val) * std::pow(10.0, exp);
            else if (!exp_str.empty())
                num = std::stol(val) * std::pow(10.0, exp);
            else
                num = std::stol(val);
            return num;
        }

        JSON parse_bool(const string &str, size_t &offset)
        {
            if (str.substr(offset, 4) == "true")
            {
                offset += 4;
                return true;
            }
            if (str.substr(offset, 5) == "false")
            {
                offset += 5;
                return false;
            }
            std::cerr << "Error: Bool: Expected true/false\n";
            return JSON::Make(JSON::Class::Null);
        }

        JSON parse_null(const string &str, size_t &offset)
        {
            if (str.substr(offset, 4) == "null")
            {
                offset += 4;
                return JSON();
            }
            std::cerr << "Error: Null: Expected null\n";
            return JSON::Make(JSON::Class::Null);
        }

        JSON parse_next(const string &str, size_t &offset)
        {
            consume_ws(str, offset);
            if (offset >= str.size())
                return JSON();

            char ch = str[offset];
            switch (ch)
            {
            case '[':
                return parse_array(str, offset);
            case '{':
                return parse_object(str, offset);
            case '\"':
                return parse_string(str, offset);
            case 't':
            case 'f':
                return parse_bool(str, offset);
            case 'n':
                return parse_null(str, offset);
            default:
                if ((ch >= '0' && ch <= '9') || ch == '-')
                    return parse_number(str, offset);
            }
            std::cerr << "Error: Parse: Unknown char '" << ch << "'\n";
            return JSON();
        }
    }

    /* -------------------------------------------------------------------------- */
    /* Public static Load function                                                */
    /* -------------------------------------------------------------------------- */
    inline JSON JSON::Load(const string &str)
    {
        size_t offset = 0;
        return parse_next(str, offset);
    }

} // namespace json