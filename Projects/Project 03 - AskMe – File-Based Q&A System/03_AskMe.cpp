/**
 * @file 03_AskMe.cpp
 * @brief AskMe – A File-Based Q&A System (Corrected, cleaned, and fully commented)
 *
 * This file contains a console-based Q&A platform inspired by Ask.fm.
 * The program stores data in two CSV-like text files that must exist in the
 * program working directory:
 *   - users.txt     -> each line = one user record (CSV fields)
 *   - questions.txt -> each line = one question record (CSV fields)
 *
 * The code below corrects a few issues in the original submission, and adds
 * extensive comments explaining the logic and the role of each function so a
 * beginner can read the file and understand how the system works.
 *
 * Design highlights / assumptions (kept for simplicity):
 *  - All CSV fields are single tokens (no commas inside any field). This keeps
 *    the parser simple for the classroom exercise.
 *  - The program uses in-memory maps and rewrites the entire file on update
 *    (simple last-write-wins concurrency model).
 *  - Threading model: a question may be a root (parent_question_id == -1) or
 *    a child (parent_question_id points to parent). Deleting a parent removes
 *    the whole thread.
 *
 * Author: Updated for readability & correctness
 * Date: 2025-10-27
 * License: MIT
 */

#include <algorithm> // std::remove, std::max
#include <fstream>   // file I/O: ifstream, ofstream
#include <iostream>  // cout, cin
#include <map>       // std::map
#include <sstream>   // std::istringstream, std::ostringstream
#include <string>    // std::string
#include <vector>    // std::vector
#include <cassert>   // assert

using namespace std; // Allowed by project instruction to keep code concise

// -----------------------------------------------------------------------------
// ------------------------- Helper Utilities ----------------------------------
// -----------------------------------------------------------------------------

/**
 * Read all non-empty lines from a file. If the file cannot be opened, an
 * empty vector is returned and an error message is printed. This wrapper uses
 * ifstream (read-only) for robustness.
 */
vector<string> ReadFileLines(const string &path)
{
    vector<string> lines;
    ifstream in(path);
    if (!in)
    {
        // File might not exist; print a friendly message and return empty list.
        cout << "\nWARNING: could not open file '" << path
             << "'. Starting with empty data.\n";
        return lines;
    }

    string line;
    while (getline(in, line))
    {
        if (!line.empty())
            lines.push_back(line);
    }
    in.close();
    return lines;
}

/**
 * Write a vector of lines to a file. If append==true the lines are appended to
 * the file; otherwise the file is overwritten. This uses ofstream to make the
 * operation explicit and safe.
 */
void WriteFileLines(const string &path, const vector<string> &lines, bool append = true)
{
    ios_base::openmode mode = ios::out | (append ? ios::app : ios::trunc);
    ofstream out(path, mode);
    if (!out)
    {
        cout << "\nERROR: Cannot open file for writing: " << path << "\n";
        return;
    }

    for (const auto &l : lines)
        out << l << '\n';

    out.close();
}

/**
 * Split a string by a delimiter and return parts. The default delimiter is a
 * comma. For this educational project we assume fields do not contain commas.
 */
vector<string> SplitString(const string &s, const string &delimiter = ",")
{
    vector<string> parts;
    size_t start = 0;
    while (true)
    {
        size_t pos = s.find(delimiter, start);
        if (pos == string::npos)
        {
            parts.push_back(s.substr(start));
            break;
        }
        parts.push_back(s.substr(start, pos - start));
        start = pos + delimiter.size();
    }
    return parts;
}

/**
 * Convert string to int (simple wrapper). If conversion fails it returns 0.
 * Using stringstream keeps behaviour simple and predictable for classroom use.
 */
int ToInt(const string &str)
{
    istringstream iss(str);
    int x = 0;
    iss >> x;
    return x;
}

/**
 * Read an integer from console in the inclusive range [low, high]. This
 * function validates user input and reprompts until a valid value is given.
 * It also clears stream errors to avoid infinite loops on invalid input.
 */
int ReadInt(int low, int high)
{
    while (true)
    {
        cout << "Enter number in range " << low << " - " << high << ": ";
        int v;
        cin >> v;
        if (cin.fail())
        {
            // Clear error and ignore the rest of the line
            cin.clear();
            string dummy;
            getline(cin, dummy);
            cout << "ERROR: Not a number. Try again.\n";
            continue;
        }
        if (v < low || v > high)
        {
            cout << "ERROR: number out of range. Try again.\n";
            continue;
        }
        // consume the rest of the line to keep input consistent
        string rest;
        getline(cin, rest);
        return v;
    }
}

/**
 * Display a simple numbered menu and return the 1-based choice index.
 * The function uses ReadInt to ensure a valid selection.
 */
int ShowReadMenu(const vector<string> &choices)
{
    cout << "\nMenu:\n";
    for (size_t i = 0; i < choices.size(); ++i)
        cout << "\t" << (i + 1) << ": " << choices[i] << "\n";

    return ReadInt(1, static_cast<int>(choices.size()));
}

// -----------------------------------------------------------------------------
// ------------------------- Data Models: Question & User -----------------------
// -----------------------------------------------------------------------------

/**
 * Question: represents a single question (possibly part of a thread) and its
 * optional answer. Fields are stored in a CSV order when persisted to file.
 *
 * CSV format (7 fields):
 * question_id,parent_question_id,from_user_id,to_user_id,is_anonymous,question_text,answer_text
 */
struct Question
{
    int question_id;
    int parent_question_id; // -1 for root questions
    int from_user_id;       // who asked
    int to_user_id;         // who is asked
    int is_anonymous;       // 1 -> anonymous, 0 -> show name
    string question_text;   // the question body
    string answer_text;     // answer body, empty if unanswered

    // Default initializer: numeric ids set to -1 meaning 'unset'
    Question()
        : question_id(-1), parent_question_id(-1), from_user_id(-1), to_user_id(-1), is_anonymous(1), question_text(""), answer_text("")
    {
    }

    // Construct from a CSV line (expects exactly 7 parts). For classroom
    // simplicity we assert the shape — if your data might contain commas you
    // should use a proper CSV parser instead.
    explicit Question(const string &line)
    {
        vector<string> parts = SplitString(line);
        assert(parts.size() == 7 && "Question CSV must have 7 fields");

        question_id = ToInt(parts[0]);
        parent_question_id = ToInt(parts[1]);
        from_user_id = ToInt(parts[2]);
        to_user_id = ToInt(parts[3]);
        is_anonymous = ToInt(parts[4]);
        question_text = parts[5];
        answer_text = parts[6];
    }

    // Convert back to CSV for storage
    string ToString() const
    {
        ostringstream oss;
        oss << question_id << ',' << parent_question_id << ',' << from_user_id << ',' << to_user_id << ',' << is_anonymous << ',' << question_text << ',' << answer_text;
        return oss.str();
    }

    // Print how this question appears to the recipient ("To Me")
    void PrintToQuestion() const
    {
        string prefix = (parent_question_id != -1) ? "\tThread: " : "";
        cout << prefix << "Question Id (" << question_id << ")";
        if (!is_anonymous)
            cout << " from user id(" << from_user_id << ")";
        cout << "\t Question: " << question_text << "\n";

        if (!answer_text.empty())
            cout << prefix << "\tAnswer: " << answer_text << "\n";
        cout << "\n";
    }

    // Print how this question appears to the sender ("From Me")
    void PrintFromQuestion() const
    {
        cout << "Question Id (" << question_id << ")";
        if (!is_anonymous)
            cout << " !AQ"; // Not Anonymous Question marker
        cout << " to user id(" << to_user_id << ")";
        cout << "\t Question: " << question_text;
        if (!answer_text.empty())
            cout << "\tAnswer: " << answer_text << "\n";
        else
            cout << "\tNOT Answered YET\n";
    }

    // Print for public feed (only answered questions should be displayed by the caller)
    void PrintFeedQuestion() const
    {
        if (parent_question_id != -1)
            cout << "Thread Parent Question ID (" << parent_question_id << ") ";
        cout << "Question Id (" << question_id << ")";
        if (!is_anonymous)
            cout << " from user id(" << from_user_id << ")";
        cout << " To user id(" << to_user_id << ")";
        cout << "\t Question: " << question_text << "\n";
        if (!answer_text.empty())
            cout << "\tAnswer: " << answer_text << "\n";
    }
};

/**
 * User: a registered user record. Stored in CSV with the following fields:
 * user_id,user_name,password,name,email,allow_anonymous_questions
 */
struct User
{
    int user_id;                   // unique id
    string user_name;              // username used for login
    string password;               // plaintext password (ok for exercise)
    string name;                   // full name
    string email;                  // email
    int allow_anonymous_questions; // 1 -> allow, 0 -> forbid

    // Helper collections that are populated after login
    vector<int> questions_id_from_me;                      // question ids asked by this user
    map<int, vector<int>> questionid_questionidsThread_to; // threads addressed to this user (parent id -> list of qids)

    User() : user_id(-1), allow_anonymous_questions(1) {}

    explicit User(const string &line)
    {
        vector<string> parts = SplitString(line);
        assert(parts.size() == 6 && "User CSV must have 6 fields");

        user_id = ToInt(parts[0]);
        user_name = parts[1];
        password = parts[2];
        name = parts[3];
        email = parts[4];
        allow_anonymous_questions = ToInt(parts[5]);
    }

    string ToString() const
    {
        ostringstream oss;
        oss << user_id << ',' << user_name << ',' << password << ',' << name << ',' << email << ',' << allow_anonymous_questions;
        return oss.str();
    }

    // Lightweight debug print (not used by UI)
    void DebugPrint() const
    {
        cout << "User " << user_id << ", username=" << user_name << ", name=" << name << ", email=" << email << "\n";
    }
};

// -----------------------------------------------------------------------------
// ------------------------- QuestionsManager ----------------------------------
// -----------------------------------------------------------------------------

class QuestionsManager
{
    // thread_map: parent_question_id -> vector of question ids that belong to that thread
    // For a root thread the key is the root's id and it contains at least the root id.
    map<int, vector<int>> thread_map;

    // Central storage: question id -> Question object
    map<int, Question> qid_to_question;

    // last assigned question id. New questions will use ++last_id.
    int last_id = 0;

public:
    // Load questions from questions.txt and build the thread map
    void LoadDatabase()
    {
        last_id = 0;
        thread_map.clear();
        qid_to_question.clear();

        vector<string> lines = ReadFileLines("questions.txt");
        for (const auto &line : lines)
        {
            // Parse question from CSV
            Question q(line);
            last_id = max(last_id, q.question_id);
            qid_to_question[q.question_id] = q;

            // Map into thread structure. If parent == -1, it's a root thread
            if (q.parent_question_id == -1)
                thread_map[q.question_id].push_back(q.question_id);
            else
                thread_map[q.parent_question_id].push_back(q.question_id);
        }
    }

    // After a user logs in we want to fill their personal lists for fast access
    void FillUserQuestions(User &user) const
    {
        user.questions_id_from_me.clear();
        user.questionid_questionidsThread_to.clear();

        // Iterate every thread and every question in the thread and add to appropriate lists
        for (const auto &entry : thread_map)
        {
            int parent_id = entry.first;
            const vector<int> &thread_ids = entry.second;
            for (int qid : thread_ids)
            {
                auto it = qid_to_question.find(qid);
                if (it == qid_to_question.end())
                    continue; // defensive: skip if missing

                const Question &q = it->second;
                if (q.from_user_id == user.user_id)
                    user.questions_id_from_me.push_back(qid);

                if (q.to_user_id == user.user_id)
                {
                    int key = (q.parent_question_id == -1) ? qid : q.parent_question_id;
                    user.questionid_questionidsThread_to[key].push_back(qid);
                }
            }
        }
    }

    // Print questions that were asked TO the given user (organized by thread)
    void PrintUserToQuestions(const User &user) const
    {
        cout << "\n";
        if (user.questionid_questionidsThread_to.empty())
        {
            cout << "No Questions\n\n";
            return;
        }

        for (const auto &entry : user.questionid_questionidsThread_to)
        {
            const vector<int> &thread_ids = entry.second;
            for (int qid : thread_ids)
            {
                qid_to_question.at(qid).PrintToQuestion();
            }
        }
        cout << "\n";
    }

    // Print questions that were asked FROM the given user
    void PrintUserFromQuestions(const User &user) const
    {
        cout << "\n";
        if (user.questions_id_from_me.empty())
        {
            cout << "No Questions\n\n";
            return;
        }

        for (int qid : user.questions_id_from_me)
            qid_to_question.at(qid).PrintFromQuestion();

        cout << "\n";
    }

    // Prompt the user to enter a question id that belongs to them (i.e. it's addressed to them)
    // Returns -1 if cancelled. Validates existence and ownership.
    int ReadQuestionIdAny(const User &user) const
    {
        while (true)
        {
            cout << "Enter Question id or -1 to cancel: ";
            int qid;
            cin >> qid;
            if (cin.fail())
            {
                cin.clear();
                string dummy;
                getline(cin, dummy);
                cout << "ERROR: not a valid id. Try again.\n";
                continue;
            }
            if (qid == -1)
            {
                string dummy;
                getline(cin, dummy);
                return -1;
            }

            auto it = qid_to_question.find(qid);
            if (it == qid_to_question.end())
            {
                cout << "\nERROR: No question with such ID. Try again\n\n";
                continue;
            }

            if (it->second.to_user_id != user.user_id)
            {
                cout << "\nERROR: Invalid question ID (not yours). Try again\n\n";
                continue;
            }
            string dummy;
            getline(cin, dummy); // consume rest of line
            return qid;
        }
    }

    // Read a parent-id for a new threaded question. -1 means new root question.
    int ReadQuestionIdThread(const User & /*user*/) const
    {
        while (true)
        {
            cout << "For thread question: Enter parent Question id or -1 for new question: ";
            int qid;
            cin >> qid;
            if (cin.fail())
            {
                cin.clear();
                string dummy;
                getline(cin, dummy);
                cout << "Invalid input. Try again.\n";
                continue;
            }
            if (qid == -1)
            {
                string dummy;
                getline(cin, dummy);
                return -1;
            }
            // We allow only parent ids that exist as keys in thread_map (i.e., root ids)
            if (thread_map.find(qid) == thread_map.end())
            {
                cout << "No thread with such Parent ID. Try again.\n";
                continue;
            }
            string dummy;
            getline(cin, dummy);
            return qid;
        }
    }

    // Answer a question addressed to the current user. Overwrites any previous answer.
    void AnswerQuestion(const User &user)
    {
        int qid = ReadQuestionIdAny(user);
        if (qid == -1)
            return;

        Question &q = qid_to_question[qid];
        q.PrintToQuestion();

        if (!q.answer_text.empty())
            cout << "\nWarning: Already answered. Answer will be updated\n";

        cout << "Enter answer (single line): ";
        string dummy;
        getline(cin, dummy);         // clear newline from previous input
        getline(cin, q.answer_text); // read full answer line
    }

    // Delete question(s). If the id is a root, delete the whole thread; if a child
    // delete only that question from its parent thread.
    void DeleteQuestion(const User &user)
    {
        int qid = ReadQuestionIdAny(user);
        if (qid == -1)
            return;

        vector<int> to_erase;

        // If qid is a parent (exists as a key in thread_map), erase entire thread
        auto thread_it = thread_map.find(qid);
        if (thread_it != thread_map.end())
        {
            to_erase = thread_it->second; // all qids in that thread
            thread_map.erase(thread_it);
        }
        else
        {
            // Otherwise remove only that child from its thread(s)
            to_erase.push_back(qid);
            for (auto &entry : thread_map)
            {
                vector<int> &vec = entry.second;
                vec.erase(remove(vec.begin(), vec.end(), qid), vec.end());
            }
        }

        // Remove deleted questions from central map
        for (int id : to_erase)
        {
            auto it = qid_to_question.find(id);
            if (it != qid_to_question.end())
                qid_to_question.erase(it);
        }
    }

    // Ask a new question. to_user_pair contains (target_user_id, allow_anonymous_flag)
    void AskQuestion(const User &user, pair<int, int> to_user_pair)
    {
        Question q;

        // Determine anonymity. If the target user forbids anonymous questions,
        // we force is_anonymous = 0 (not anonymous).
        if (!to_user_pair.second)
        {
            cout << "Note: Anonymous questions are not allowed for this user\n";
            q.is_anonymous = 0;
        }
        else
        {
            cout << "Is anonymous? (1 = anonymous, 0 = not anonymous): ";
            int a;
            cin >> a;
            // Normalize input to 0 or 1
            q.is_anonymous = (a != 0) ? 1 : 0;
        }

        // Parent thread id: -1 for a new root question or an existing parent id
        q.parent_question_id = ReadQuestionIdThread(user);

        cout << "Enter question text (single line): ";
        string dummy;
        getline(cin, dummy); // clear newline
        getline(cin, q.question_text);

        q.from_user_id = user.user_id;
        q.to_user_id = to_user_pair.first;
        q.question_id = ++last_id; // assign unique id

        // Store question and update thread map
        qid_to_question[q.question_id] = q;
        if (q.parent_question_id == -1)
            thread_map[q.question_id].push_back(q.question_id);
        else
            thread_map[q.parent_question_id].push_back(q.question_id);
    }

    // List public feed (answered questions)
    void ListFeed() const
    {
        for (const auto &entry : qid_to_question)
        {
            const Question &q = entry.second;
            if (!q.answer_text.empty())
                q.PrintFeedQuestion();
        }
    }

    // Persist all questions back to the file (overwrite)
    void UpdateDatabase() const
    {
        vector<string> lines;
        for (const auto &entry : qid_to_question)
        {
            lines.push_back(entry.second.ToString());
        }
        WriteFileLines("questions.txt", lines, false);
    }
};

// -----------------------------------------------------------------------------
// ------------------------- UsersManager --------------------------------------
// -----------------------------------------------------------------------------

class UsersManager
{
    map<string, User> username_to_user; // user_name -> User
    User current_user;                  // the user who is currently logged in
    int last_id = 0;                    // last assigned user id

public:
    // Load users from users.txt
    void LoadDatabase()
    {
        last_id = 0;
        username_to_user.clear();

        vector<string> lines = ReadFileLines("users.txt");
        for (const auto &line : lines)
        {
            User u(line);
            username_to_user[u.user_name] = u;
            last_id = max(last_id, u.user_id);
        }
    }

    // Show login/signup menu and perform selected action
    void AccessSystem()
    {
        int choice = ShowReadMenu({"Login", "Sign Up"});
        if (choice == 1)
            DoLogin();
        else
            DoSignUp();
    }

private:
    // Perform login: validate username and password
    void DoLogin()
    {
        LoadDatabase(); // fresh copy from file
        while (true)
        {
            cout << "Enter user name & password: ";
            string uname, pwd;
            cin >> uname >> pwd;

            auto it = username_to_user.find(uname);
            if (it == username_to_user.end() || it->second.password != pwd)
            {
                cout << "\nInvalid user name or password. Try again\n\n";
                continue;
            }

            current_user = it->second; // login successful
            break;
        }
    }

    // Sign up a new user and save to disk
    void DoSignUp()
    {
        LoadDatabase(); // ensure we check uniqueness with latest data
        while (true)
        {
            cout << "Enter user name (no spaces): ";
            cin >> current_user.user_name;
            if (username_to_user.count(current_user.user_name))
                cout << "Already used. Try again\n";
            else
                break;
        }

        cout << "Enter password: ";
        cin >> current_user.password;
        cout << "Enter full name: ";
        cin >> ws; // eat whitespace so getline reads the name correctly
        getline(cin, current_user.name);
        cout << "Enter email: ";
        cin >> current_user.email;
        cout << "Allow anonymous questions? (0 or 1): ";
        cin >> current_user.allow_anonymous_questions;

        current_user.user_id = ++last_id;
        username_to_user[current_user.user_name] = current_user;
        SaveAllUsers(); // persist the updated user list
    }

public:
    // Print all users (id and name)
    void ListUsersNamesIds() const
    {
        for (const auto &entry : username_to_user)
        {
            const User &u = entry.second;
            cout << "ID: " << u.user_id << "\t\tName: " << u.name << "\n";
        }
    }

    // Read a user id (returns pair: <id, allow_anonymous_flag>)
    pair<int, int> ReadUserId() const
    {
        while (true)
        {
            cout << "Enter User id or -1 to cancel: ";
            int uid;
            cin >> uid;
            if (cin.fail())
            {
                cin.clear();
                string dummy;
                getline(cin, dummy);
                cout << "Invalid input\n";
                continue;
            }
            if (uid == -1)
                return {-1, -1};

            for (const auto &entry : username_to_user)
            {
                const User &u = entry.second;
                if (u.user_id == uid)
                    return {uid, u.allow_anonymous_questions};
            }
            cout << "Invalid User ID. Try again\n";
        }
    }

    // Save all users to disk (overwrite users.txt)
    void SaveAllUsers() const
    {
        vector<string> lines;
        for (const auto &entry : username_to_user)
            lines.push_back(entry.second.ToString());
        WriteFileLines("users.txt", lines, false);
    }

    // Expose current user (const and non-const versions)
    const User &GetCurrentUser() const { return current_user; }
    User &GetCurrentUser() { return current_user; }
};

// -----------------------------------------------------------------------------
// ------------------------- AskMeSystem (Main App) ----------------------------
// -----------------------------------------------------------------------------

class AskMeSystem
{
    UsersManager users_mgr;
    QuestionsManager questions_mgr;

    // Helper to load databases and optionally populate the logged-in user's
    // personal lists of questions.
    void LoadDatabase(bool fill_user_questions = false)
    {
        users_mgr.LoadDatabase();
        questions_mgr.LoadDatabase();
        if (fill_user_questions)
            questions_mgr.FillUserQuestions(users_mgr.GetCurrentUser());
    }

public:
    // run(): main loop. The outer loop supports re-login after logout without
    // recursive calls so the program remains stable.
    void run()
    {
        while (true)
        {
            // Load initial database and perform login/signup
            LoadDatabase();
            users_mgr.AccessSystem(); // will set current user inside manager

            // After login, build user-specific indexes for questions
            questions_mgr.FillUserQuestions(users_mgr.GetCurrentUser());

            // Menu visible to a logged-in user
            const vector<string> menu = {
                "Print Questions To Me",
                "Print Questions From Me",
                "Answer Question",
                "Delete Question",
                "Ask Question",
                "List System Users",
                "Feed",
                "Logout"};

            // Session loop for the logged-in user
            while (true)
            {
                int choice = ShowReadMenu(menu);

                // Reload the databases to reflect any external changes and to
                // ensure we operate on the latest data. We also refresh the
                // logged-in user's personal question lists.
                LoadDatabase(true);

                if (choice == 1)
                    questions_mgr.PrintUserToQuestions(users_mgr.GetCurrentUser());
                else if (choice == 2)
                    questions_mgr.PrintUserFromQuestions(users_mgr.GetCurrentUser());
                else if (choice == 3)
                {
                    questions_mgr.AnswerQuestion(users_mgr.GetCurrentUser());
                    questions_mgr.UpdateDatabase();
                }
                else if (choice == 4)
                {
                    questions_mgr.DeleteQuestion(users_mgr.GetCurrentUser());
                    questions_mgr.FillUserQuestions(users_mgr.GetCurrentUser());
                    questions_mgr.UpdateDatabase();
                }
                else if (choice == 5)
                {
                    auto target = users_mgr.ReadUserId();
                    if (target.first != -1)
                    {
                        questions_mgr.AskQuestion(users_mgr.GetCurrentUser(), target);
                        questions_mgr.UpdateDatabase();
                    }
                }
                else if (choice == 6)
                {
                    users_mgr.ListUsersNamesIds();
                }
                else if (choice == 7)
                {
                    questions_mgr.ListFeed();
                }
                else
                {
                    // Logout chosen - break session loop and go to outer loop
                    break;
                }
            }

            // After logout the outer loop will re-run and show login/signup
            cout << "Logging out... returning to login menu.\n";
        }
    }
};

// -----------------------------------------------------------------------------
// ------------------------- main() -------------------------------------------
// -----------------------------------------------------------------------------

int main()
{
    AskMeSystem app;
    app.run();
    return 0;
}
