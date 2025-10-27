/**
 * @file 04_AskMe.cpp
 * @brief AskMe v0.4 — Upgraded File-Based Q&A System (clean, fixed, fully commented)
 *
 * Project description:
 * This is an educational console Q&A system inspired by Ask.fm. It stores
 * data in two CSV-like text files placed in the program working directory:
 *   - users.txt     (user records)
 *   - questions.txt (question records)
 *
 * Major features (same as earlier version, but cleaned and improved):
 *  - Sign up / Login
 *  - Ask questions (anonymous or named)
 *  - Threaded questions (parent-child relationships)
 *  - Answer and delete questions (only by the receiver)
 *  - View: Questions To Me, Questions From Me, Public Feed (answered)
 *
 * Design & style requirements (followed):
 *  - Only necessary headers are included.
 *  - The file begins with a full description and Doxygen-style comments.
 *  - Functions and classes are documented in Doxygen style.
 *  - Extensive inline comments are provided so a beginner can follow the
 *    code line-by-line.
 *
 * Assumptions & limitations (for classroom exercises):
 *  - CSV fields do NOT contain commas (so SplitString by comma is safe).
 *  - Concurrency: last-write-wins. If two program instances run simultaneously
 *    they can cause inconsistent IDs — acceptable for this assignment.
 *  - No password hashing (plain text) — ok for educational purposes only.
 *
 * Author: MD. Ualiur Rahman Rahat (project student)
 * Date: 2025-10-27
 * License: MIT
 */

// ---------------------- Required Headers ----------------------
#include <algorithm> // std::remove, std::max
#include <fstream>   // file streams
#include <iostream>  // cout, cin
#include <map>       // std::map
#include <sstream>   // istringstream, ostringstream
#include <string>    // std::string
#include <vector>    // std::vector
#include <cassert>   // assert()

using namespace std; // project instruction: use this for conciseness

// ---------------------- File constants ------------------------
const string USERS_FILE = "users.txt";
const string QUESTIONS_FILE = "questions.txt";

// ---------------------- Helper Utilities ----------------------

/**
 * Read all non-empty lines from a file. If file cannot be opened returns an
 * empty vector and prints a friendly warning (so program still works).
 * @param path path to file
 * @return vector of non-empty lines
 */
vector<string> ReadFileLines(const string &path) {
    vector<string> lines;                 // container for lines
    ifstream in(path);                    // open read-only
    if (!in) {                            // if file failed to open
        cout << "\nWARNING: could not open file '" << path << "'. Starting with empty data.\n";
        return lines;                     // return empty vector
    }

    string line;                          // temporary line storage
    while (getline(in, line)) {           // read line by line
        if (!line.empty())                // skip empty lines
            lines.push_back(line);        // add to result
    }
    in.close();                           // close file
    return lines;                         // return collected lines
}

/**
 * Write a vector of lines to a file.
 * @param path destination file
 * @param lines lines to write (each entry becomes a line)
 * @param append if true append to file; if false overwrite
 */
void WriteFileLines(const string &path, const vector<string> &lines, bool append = true) {
    ios::openmode mode = ios::out | (append ? ios::app : ios::trunc);
    ofstream out(path, mode);
    if (!out) {
        cout << "\nERROR: cannot open file for writing: " << path << "\n";
        return;
    }
    for (const auto &l : lines)
        out << l << '\n';
    out.close();
}

/**
 * Split string by delimiter (default: comma). For this project we assume
 * fields contain no commas so this simple splitter is safe.
 * @param s input string
 * @param delimiter delimiter string (default: ",")
 * @return vector of parts
 */
vector<string> SplitString(const string &s, const string &delimiter = ",") {
    vector<string> parts;
    size_t start = 0;
    while (true) {
        size_t pos = s.find(delimiter, start);
        if (pos == string::npos) {
            parts.push_back(s.substr(start));
            break;
        }
        parts.push_back(s.substr(start, pos - start));
        start = pos + delimiter.size();
    }
    return parts;
}

/**
 * Convert string to int. If conversion fails returns 0.
 * @param str string containing integer
 * @return parsed integer
 */
int ToInt(const string &str) {
    istringstream iss(str);
    int x = 0;
    iss >> x;
    return x;
}

/**
 * Read an integer from stdin constrained to [low, high], reprompt on invalid
 * input. This function eats any leftover line to keep cin in a clean state.
 */
int ReadInt(int low, int high) {
    while (true) {
        cout << "Enter number in range " << low << " - " << high << ": ";
        int v;
        cin >> v;
        if (cin.fail()) {
            cin.clear();                 // clear error flags
            string dummy; getline(cin, dummy); // discard rest of line
            cout << "ERROR: Not a number. Try again.\n";
            continue;
        }
        if (v < low || v > high) {
            cout << "ERROR: Out of range. Try again.\n";
            string dummy; getline(cin, dummy);
            continue;
        }
        string dummy; getline(cin, dummy); // clear rest of line
        return v;
    }
}

/**
 * Show a numbered menu based on choices and return 1-based index of chosen
 * option. Uses ReadInt for validation.
 */
int ShowReadMenu(const vector<string> &choices) {
    cout << "\nMenu:\n";
    for (size_t i = 0; i < choices.size(); ++i)
        cout << "\t" << (i + 1) << ": " << choices[i] << "\n";
    return ReadInt(1, static_cast<int>(choices.size()));
}

// ---------------------- Data Models ----------------------------------------

/**
 * @struct Question
 * @brief Represents a single question and optional answer. Threading via
 * parent_question_id (-1 means root question).
 *
 * CSV format: question_id,parent_question_id,from_user_id,to_user_id,is_anonymous,question_text,answer_text
 */
struct Question {
    int question_id = -1;          // unique identifier
    int parent_question_id = -1;   // -1 => root question
    int from_user_id = -1;         // who asked
    int to_user_id = -1;           // who is asked
    int is_anonymous = 1;          // 1 => anonymous, 0 => show name
    string question_text;          // question body
    string answer_text;            // answer body (empty if unanswered)

    Question() = default; // default constructor

    /**
     * Construct from CSV line (expects 7 parts). Asserts shape for classroom use.
     */
    explicit Question(const string &line) {
        vector<string> p = SplitString(line);
        assert(p.size() == 7 && "Question line must have 7 fields");
        question_id = ToInt(p[0]);
        parent_question_id = ToInt(p[1]);
        from_user_id = ToInt(p[2]);
        to_user_id = ToInt(p[3]);
        is_anonymous = ToInt(p[4]);
        question_text = p[5];
        answer_text = p[6];
    }

    /**
     * Convert to CSV line for persistence.
     */
    string ToString() const {
        ostringstream oss;
        oss << question_id << ',' << parent_question_id << ',' << from_user_id << ',' << to_user_id << ',' << is_anonymous << ',' << question_text << ',' << answer_text;
        return oss.str();
    }

    // --- Print helpers (how question appears in different contexts) ---
    void PrintToQuestion() const {
        string prefix = (parent_question_id != -1) ? "\tThread: " : "";
        cout << prefix << "Question Id (" << question_id << ")";
        if (!is_anonymous)
            cout << " from user id(" << from_user_id << ")";
        cout << "\t Question: " << question_text << "\n";
        if (!answer_text.empty())
            cout << prefix << "\tAnswer: " << answer_text << "\n";
        cout << "\n";
    }

    void PrintFromQuestion() const {
        cout << "Question Id (" << question_id << ")";
        if (!is_anonymous)
            cout << " !AQ"; // not anonymous marker
        cout << " to user id(" << to_user_id << ")\t Question: " << question_text;
        if (!answer_text.empty())
            cout << "\tAnswer: " << answer_text << "\n";
        else
            cout << "\tNOT Answered YET\n";
    }

    void PrintFeedQuestion() const {
        if (parent_question_id != -1)
            cout << "Thread Parent Question ID (" << parent_question_id << ") ";
        cout << "Question Id (" << question_id << ")";
        if (!is_anonymous)
            cout << " from user id(" << from_user_id << ")";
        cout << " To user id(" << to_user_id << ")\t Question: " << question_text << "\n";
        if (!answer_text.empty())
            cout << "\tAnswer: " << answer_text << "\n";
    }
};

/**
 * @struct User
 * @brief Represents a registered user. CSV format:
 * user_id,user_name,password,name,email,allow_anonymous_questions
 */
struct User {
    int user_id = -1;
    string user_name;
    string password;
    string name;
    string email;
    int allow_anonymous_questions = 1; // default allow

    // cached lists (filled after login)
    vector<int> questions_id_from_me;                 // questions I asked
    map<int, vector<int>> questionid_questionidsThread_to; // parentID -> qids addressed to me

    User() = default;

    explicit User(const string &line) {
        vector<string> p = SplitString(line);
        assert(p.size() == 6 && "User line must have 6 fields");
        user_id = ToInt(p[0]);
        user_name = p[1];
        password = p[2];
        name = p[3];
        email = p[4];
        allow_anonymous_questions = ToInt(p[5]);
    }

    string ToString() const {
        ostringstream oss;
        oss << user_id << ',' << user_name << ',' << password << ',' << name << ',' << email << ',' << allow_anonymous_questions;
        return oss.str();
    }

    // Methods to populate the cached lists
    void ResetToQuestions(const vector<int> &to_questions) {
        questions_id_from_me = to_questions; // copy is fine
    }
    void ResetFromQuestions(const vector<pair<int,int>> &from_questions) {
        questionid_questionidsThread_to.clear();
        for (const auto &pr : from_questions)
            questionid_questionidsThread_to[pr.first].push_back(pr.second);
    }

    // Read interactive user fields during signup (no spaces for username)
    void ReadUser(const string &uname, int id) {
        user_name = uname;
        user_id = id;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter full name: ";
        cin >> ws; getline(cin, name);
        cout << "Enter email: ";
        cin >> email;
        cout << "Allow anonymous questions? (0 or 1): ";
        cin >> allow_anonymous_questions;
    }
};

// ---------------------- QuestionsManager -----------------------------------

/**
 * @class QuestionsManager
 * @brief Loads all questions into memory and provides helpers to query and
 * manipulate them (ask, answer, delete, list feed).
 */
class QuestionsManager {
    // thread map: parentID -> list of qids (root parent's vector includes root id itself)
    map<int, vector<int>> thread_map;
    // central storage: qid -> Question
    map<int, Question> qid_to_question;
    int last_id = 0; // highest used id

public:
    QuestionsManager() = default;

    /**
     * Load questions from QUESTIONS_FILE and build in-memory indexes.
     */
    void LoadDatabase() {
        last_id = 0;
        thread_map.clear();
        qid_to_question.clear();

        vector<string> lines = ReadFileLines(QUESTIONS_FILE);
        for (const auto &ln : lines) {
            Question q(ln);                       // parse CSV line
            last_id = max(last_id, q.question_id); // update last id seen
            qid_to_question[q.question_id] = q;   // store question
            if (q.parent_question_id == -1)
                thread_map[q.question_id].push_back(q.question_id);
            else
                thread_map[q.parent_question_id].push_back(q.question_id);
        }
    }

    /**
     * Return list of question IDs that the user asked (From Me)
     */
    vector<int> GetUserToQuestions(const User &user) const {
        vector<int> out;
        for (const auto &entry : qid_to_question) {
            const Question &q = entry.second;
            if (q.from_user_id == user.user_id)
                out.push_back(q.question_id);
        }
        return out;
    }

    /**
     * Return list of pairs (parent_id, qid) for questions that were asked to
     * the user (To Me). The parent_id is the thread parent id (or qid if root)
     */
    vector<pair<int,int>> GetUserFromQuestions(const User &user) const {
        vector<pair<int,int>> out;
        for (const auto &entry : thread_map) {
            int parent = entry.first;
            for (int qid : entry.second) {
                auto it = qid_to_question.find(qid);
                if (it == qid_to_question.end()) continue;
                const Question &q = it->second;
                if (q.to_user_id == user.user_id) {
                    int key = (q.parent_question_id == -1) ? qid : q.parent_question_id;
                    out.emplace_back(key, qid);
                }
            }
        }
        return out;
    }

    /**
     * Print questions addressed to the user using the user's cached thread map
     */
    void PrintUserToQuestions(const User &user) const {
        cout << "\n";
        if (user.questionid_questionidsThread_to.empty()) {
            cout << "No Questions\n\n";
            return;
        }
        for (const auto &entry : user.questionid_questionidsThread_to) {
            for (int qid : entry.second) {
                auto it = qid_to_question.find(qid);
                if (it != qid_to_question.end())
                    it->second.PrintToQuestion();
            }
        }
        cout << "\n";
    }

    /**
     * Print questions sent by the user (From Me)
     */
    void PrintUserFromQuestions(const User &user) const {
        cout << "\n";
        if (user.questions_id_from_me.empty()) {
            cout << "No Questions\n\n";
            return;
        }
        for (int qid : user.questions_id_from_me) {
            auto it = qid_to_question.find(qid);
            if (it != qid_to_question.end())
                it->second.PrintFromQuestion();
        }
        cout << "\n";
    }

    /**
     * Read a question id that belongs to the current user (i.e., is addressed
     * to them). Returns -1 if cancelled. Validates existence & ownership.
     */
    int ReadQuestionIdAny(const User &user) const {
        while (true) {
            cout << "Enter Question id or -1 to cancel: ";
            int qid; cin >> qid;
            if (cin.fail()) { cin.clear(); string dum; getline(cin, dum); cout << "Invalid input\n"; continue; }
            if (qid == -1) { string dum; getline(cin, dum); return -1; }
            auto it = qid_to_question.find(qid);
            if (it == qid_to_question.end()) { cout << "\nERROR: No question with such ID. Try again\n\n"; continue; }
            if (it->second.to_user_id != user.user_id) { cout << "\nERROR: Invalid question ID (not yours). Try again\n\n"; continue; }
            string dum; getline(cin, dum); return qid;
        }
    }

    /**
     * Read a parent question id for threading. -1 means create a new root.
     */
    int ReadQuestionIdThread(const User & /*user*/) const {
        while (true) {
            cout << "For thread question: Enter parent Question id or -1 for new question: ";
            int qid; cin >> qid;
            if (cin.fail()) { cin.clear(); string dum; getline(cin, dum); cout << "Invalid input\n"; continue; }
            if (qid == -1) { string dum; getline(cin, dum); return -1; }
            if (thread_map.find(qid) == thread_map.end()) { cout << "No thread question with such ID. Try again\n"; continue; }
            string dum; getline(cin, dum); return qid;
        }
    }

    /**
     * Answer a question addressed to the user. Overwrites previous answer if any.
     */
    void AnswerQuestion(const User &user) {
        int qid = ReadQuestionIdAny(user);
        if (qid == -1) return;
        Question &q = qid_to_question[qid];
        q.PrintToQuestion();
        if (!q.answer_text.empty()) cout << "\nWarning: Already answered. Answer will be updated\n";
        cout << "Enter answer (single line): "; string dummy; getline(cin, dummy); getline(cin, q.answer_text);
    }

    /**
     * Delete a question. If it's a parent, delete entire thread. Otherwise
     * delete just the child and remove it from its thread vector.
     */
    void DeleteQuestion(const User &user) {
        int qid = ReadQuestionIdAny(user);
        if (qid == -1) return;
        vector<int> toErase;
        auto threadIt = thread_map.find(qid);
        if (threadIt != thread_map.end()) {
            toErase = threadIt->second;
            thread_map.erase(threadIt);
        } else {
            toErase.push_back(qid);
            for (auto &entry : thread_map) {
                auto &vec = entry.second;
                vec.erase(remove(vec.begin(), vec.end(), qid), vec.end());
            }
        }
        for (int id : toErase) qid_to_question.erase(id);
    }

    /**
     * Ask a new question to a target user. to_user_pair = {target_user_id, allow_anonymous_flag}
     */
    void AskQuestion(const User &user, const pair<int,int> &to_user_pair) {
        Question q;
        if (!to_user_pair.second) {
            cout << "Note: Anonymous questions are not allowed for this user\n";
            q.is_anonymous = 0;
        } else {
            cout << "Is anonymous? (1 = anonymous, 0 = not anonymous): "; int a; cin >> a; q.is_anonymous = (a != 0) ? 1 : 0;
        }
        q.parent_question_id = ReadQuestionIdThread(user);
        cout << "Enter question text (single line): "; string dummy; getline(cin, dummy); getline(cin, q.question_text);
        q.from_user_id = user.user_id; q.to_user_id = to_user_pair.first;
        q.question_id = ++last_id; // assign new id
        qid_to_question[q.question_id] = q; // store
        if (q.parent_question_id == -1)
            thread_map[q.question_id].push_back(q.question_id);
        else
            thread_map[q.parent_question_id].push_back(q.question_id);
    }

    /**
     * List public feed — all answered questions.
     */
    void ListFeed() const {
        for (const auto &entry : qid_to_question) {
            const Question &q = entry.second;
            if (q.answer_text.empty()) continue;
            q.PrintFeedQuestion();
        }
    }

    /**
     * Persist all questions to QUESTIONS_FILE (overwrite).
     */
    void UpdateDatabase() const {
        vector<string> lines;
        for (const auto &entry : qid_to_question)
            lines.push_back(entry.second.ToString());
        WriteFileLines(QUESTIONS_FILE, lines, false);
    }
};

// ---------------------- UsersManager ---------------------------------------

/**
 * UsersManager: loads users, handles login/signup and exposes current user.
 */
class UsersManager {
    map<string, User> username_to_user; // key = username
    User current_user;
    int last_id = 0;

public:
    UsersManager() = default;

    /**
     * Load users from USERS_FILE into username_to_user map.
     */
    void LoadDatabase() {
        last_id = 0; username_to_user.clear();
        vector<string> lines = ReadFileLines(USERS_FILE);
        for (const auto &ln : lines) {
            User u(ln);
            username_to_user[u.user_name] = u;
            last_id = max(last_id, u.user_id);
        }
    }

    /**
     * Show login/signup menu and perform chosen action. After login current_user
     * will be set.
     */
    void AccessSystem() {
        int choice = ShowReadMenu({"Login", "Sign Up"});
        if (choice == 1) DoLogin(); else DoSignUp();
    }

    // Login implementation: validate username & password
    void DoLogin() {
        LoadDatabase();
        while (true) {
            cout << "Enter user name & password: ";
            string uname, pwd; cin >> uname >> pwd;
            auto it = username_to_user.find(uname);
            if (it == username_to_user.end() || it->second.password != pwd) {
                cout << "\nInvalid user name or password. Try again\n\n";
                continue;
            }
            current_user = it->second; break;
        }
    }

    // Sign up implementation: gather details, assign id, save
    void DoSignUp() {
        LoadDatabase();
        string uname;
        while (true) {
            cout << "Enter user name (no spaces): "; cin >> uname;
            if (username_to_user.count(uname)) cout << "Already used. Try again\n";
            else break;
        }
        User u; u.ReadUser(uname, ++last_id);
        username_to_user[u.user_name] = u;
        SaveAllUsers();
        current_user = u;
    }

    // List users id & name
    void ListUsersNamesIds() const {
        for (const auto &entry : username_to_user)
            cout << "ID: " << entry.second.user_id << "\t\tName: " << entry.second.name << "\n";
    }

    /**
     * Read user id interactively and return pair<id, allow_anonymous_flag>.
     * If -1 returned first element is -1 (cancel).
     */
    pair<int,int> ReadUserId() const {
        while (true) {
            cout << "Enter User id or -1 to cancel: ";
            int uid; cin >> uid;
            if (cin.fail()) { cin.clear(); string dum; getline(cin, dum); cout << "Invalid input\n"; continue; }
            if (uid == -1) return {-1,-1};
            for (const auto &entry : username_to_user) {
                if (entry.second.user_id == uid) return {uid, entry.second.allow_anonymous_questions};
            }
            cout << "Invalid User ID. Try again\n";
        }
    }

    // Persist all users to USERS_FILE (overwrite)
    void SaveAllUsers() const {
        vector<string> lines;
        for (const auto &entry : username_to_user)
            lines.push_back(entry.second.ToString());
        WriteFileLines(USERS_FILE, lines, false);
    }

    const User& GetCurrentUser() const { return current_user; }
    User& GetCurrentUser() { return current_user; }
};

// ---------------------- Application Orchestrator --------------------------

/**
 * AskMeSystem: orchestrates managers and runs the interactive console loop.
 */
class AskMeSystem {
    UsersManager users_mgr;
    QuestionsManager questions_mgr;

    // After login we need to populate the user's cached lists
    void ResetCurrentUserQuestions() {
        User &u = users_mgr.GetCurrentUser();
        auto to = questions_mgr.GetUserToQuestions(u);
        u.ResetToQuestions(to);
        auto from = questions_mgr.GetUserFromQuestions(u);
        u.ResetFromQuestions(from);
    }

public:
    void Run() {
        // Outer loop so we can logout and login again without recursion
        while (true) {
            users_mgr.LoadDatabase();
            questions_mgr.LoadDatabase();
            users_mgr.AccessSystem();        // login/signup chosen
            ResetCurrentUserQuestions();     // prepare user-specific views

            vector<string> menu = {
                "Print Questions To Me",
                "Print Questions From Me",
                "Answer Question",
                "Delete Question",
                "Ask Question",
                "List System Users",
                "Feed",
                "Logout"
            };

            // Session loop for the logged-in user
            while (true) {
                int choice = ShowReadMenu(menu);
                // Reload data and rebuild user views to reflect external changes
                users_mgr.LoadDatabase();
                questions_mgr.LoadDatabase();
                ResetCurrentUserQuestions();

                const User &cur = users_mgr.GetCurrentUser();

                if (choice == 1)
                    questions_mgr.PrintUserToQuestions(cur);
                else if (choice == 2)
                    questions_mgr.PrintUserFromQuestions(cur);
                else if (choice == 3) {
                    questions_mgr.AnswerQuestion(cur);
                    questions_mgr.UpdateDatabase();
                } else if (choice == 4) {
                    questions_mgr.DeleteQuestion(cur);
                    // rebuild user's view then persist
                    ResetCurrentUserQuestions();
                    questions_mgr.UpdateDatabase();
                } else if (choice == 5) {
                    auto target = users_mgr.ReadUserId();
                    if (target.first != -1) {
                        questions_mgr.AskQuestion(users_mgr.GetCurrentUser(), target);
                        questions_mgr.UpdateDatabase();
                    }
                } else if (choice == 6)
                    users_mgr.ListUsersNamesIds();
                else if (choice == 7)
                    questions_mgr.ListFeed();
                else // Logout
                    break;
            }

            cout << "Logging out...\n";
        }
    }
};

// ---------------------- main -----------------------------------------------

int main() {
    // Helpful comment: If users.txt or questions.txt do not exist, program will
    // start with empty data and create them when SaveAllUsers/UpdateDatabase is called.

    AskMeSystem app;
    app.Run();
    return 0;
}

/*
Sample data you can copy to users.txt and questions.txt for testing (place in working directory):

# questions.txt (each line is CSV as described above):
101,-1,11,13,0,Should I learn C++ first or Java,I think C++ is a better Start
203,101,11,13,0,Why do you think so!,Just Google. There is an answer on Quora.
205,101,45,13,0,What about python?,
211,-1,13,11,1,It was nice to chat to you,For my pleasure Dr Mostafa
212,-1,13,45,0,Please search archive before asking,
300,101,11,13,1,Is it ok to learn Java for OOP?,Good choice
301,-1,11,13,0,Free to meet?,
302,101,11,13,1,Why so late in reply?,

# users.txt (one user per line):
13,mostafa,111,mostafa_saad_ibrahim,mostafa@gmail.com,1
11,noha,222,noha_salah,nono171@gmail.com,0
45,ali,333,ali_wael,wael@gmail.com,0
*/