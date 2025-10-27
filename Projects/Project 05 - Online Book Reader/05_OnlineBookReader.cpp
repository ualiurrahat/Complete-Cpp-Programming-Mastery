/**
 * @file 05_OnlineBookReader.cpp
 * @brief Online Book Reader System - Project 05

 *
 * =================================================================================
 * PROJECT DESCRIPTION
 * =================================================================================
 *
 * @section intro Introduction
 * This is a console-based **Online Book Reader System** written in C++ as part of
 * a programming course by **Mostafa S. Ibrahim**. The system simulates an online
 * library where:
 *   - Admins can log in and **add books**.
 *   - Users (customers) can **sign up/login**, **read books**, and **resume reading**
 *     from where they left off.
 *
 * @section features Functional Requirements
 * - Two types of users:
 *   - **Admin**: Can add books.
 *   - **Customer**: Can read books, maintain reading sessions.
 * - Users can:
 *   - View profile
 *   - View reading history (multiple sessions per book allowed)
 *   - Browse available books and start reading
 *   - Navigate pages (next/previous)
 *   - Resume reading from last page
 * - Sessions persist across logouts (in memory)
 *
 * @section nonfunc Non-Functional Requirements
 * - Usability: Simple menu-driven interface
 * - No file I/O (in-memory database)
 * - Single-threaded, single-user session at a time
 * - Input validation (no spaces, proper ranges)
 *
 * @section design Design Highlights
 * - **Separation of Concerns**: UsersManager, BooksManager, Views
 * - **Ownership Model**: Pointers used with clear ownership (RAII via destructors)
 * - **No Copying**: Managers and User objects are non-copyable
 * - **Session Safety**: Reading sessions store `Book*` — risk of dangling pointer if
 *   book is deleted (not implemented). Future: use ISBN + lookup.
 *
 * @section dummydata Dummy Data
 * - Admin: `rahat` / `111`
 * - Customer: `tamanna` / `222`
 * - 3 preloaded books
 *
 * @section notes Important Notes
 * - Avoid spaces in all inputs
 * - Program runs in an infinite loop until manually terminated
 * - Memory is freed properly in destructors
 *
 * =================================================================================
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
#include <set>
#include <chrono>
#include <iomanip>

using namespace std;

/** @defgroup utilities Utility Functions
 *  @{
 */

/**
 * @brief Reads an integer within a specified range with validation.
 * @param low Lower bound (inclusive)
 * @param high Upper bound (inclusive)
 * @return Valid integer in range [low, high]
 *
 * This function repeatedly prompts the user until a valid integer
 * in the given range is entered. It improves user experience by
 * preventing crashes due to invalid input.
 */
int ReadInt(int low, int high)
{
    cout << "\nEnter number in range " << low << " - " << high << ": ";
    int value;
    cin >> value;

    // Validate input range
    if (low <= value && value <= high)
        return value;

    // Inform user and retry recursively
    cout << "ERROR: invalid number...Try again\n";
    return ReadInt(low, high);
}

/**
 * @brief Displays a numbered menu and returns user's choice.
 * @param choices Vector of menu option strings
 * @return Selected option index (1-based)
 *
 * Prints each choice with a number and uses ReadInt() to ensure
 * valid selection. Returns 1-based index for user-friendliness.
 */
int ShowReadMenu(const vector<string> &choices)
{
    cout << "\nMenu:\n";
    for (int ch = 0; ch < (int)choices.size(); ++ch)
    {
        cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
    }
    return ReadInt(1, choices.size());
}

/**
 * @brief Returns current date and time as formatted string.
 * @return String in format "YYYY-MM-DD HH:MM:SS"
 *
 * Uses std::chrono to get current time and formats it using
 * std::put_time. Useful for timestamping reading sessions.
 */
string GetCurrentTimeDate()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

/** @} */ // End of utilities group

/** @class Book
 *  @brief Represents a book with ISBN, title, author, and pages.
 */
class Book
{
private:
    string isbn;
    string title;
    string author;
    vector<string> pages;

public:
    void Read()
    {
        string str;

        cout << "Enter ISBN: ";
        cin >> str;
        SetIsbn(str);

        cout << "Enter Title: ";
        cin >> str;
        SetTitle(str);

        cout << "Enter Author Name: ";
        cin >> str;
        SetAuthor(str);

        cout << "Enter How many pages: ";
        int pages_count;
        cin >> pages_count;

        pages.clear();
        for (int page = 0; page < pages_count; ++page)
        {
            cout << "Enter page # " << page + 1 << ": ";
            cin >> str;
            pages.push_back(str);
        }
    }

    const string &GetAuthor() const { return author; }
    const string &GetIsbn() const { return isbn; }
    const vector<string> &GetPages() const { return pages; }
    const string &GetTitle() const { return title; }

    void SetAuthor(const string &author) { this->author = author; }
    void SetIsbn(const string &isbn) { this->isbn = isbn; }
    void SetPages(const vector<string> &pages) { this->pages = pages; }
    void SetTitle(const string &title) { this->title = title; }

    string ToString() { return title; }
};

/** @class BookReadingSession
 *  @brief Tracks a user's reading progress in a specific book.
 */
class BookReadingSession
{
private:
    Book *book;
    int current_page;
    string last_access_date;

public:
    BookReadingSession() : BookReadingSession(nullptr) {}
    BookReadingSession(Book *book)
        : book(book), current_page(0), last_access_date(GetCurrentTimeDate()) {}

    string ToString()
    {
        ostringstream oss;
        oss << GetBook()->GetTitle()
            << " Page: " << PageIdxStr()
            << " - " << GetLastAccessDate();
        return oss.str();
    }

    string GetCurrentPageContent()
    {
        return book->GetPages()[current_page];
    }

    const Book *GetBook() const { return book; }
    const string &GetLastAccessDate() const { return last_access_date; }
    void ResetLastAccessDate() { last_access_date = GetCurrentTimeDate(); }
    int GetCurrentPage() const { return current_page; }

    string PageIdxStr()
    {
        ostringstream oss;
        oss << GetCurrentPage() + 1 << "/" << book->GetPages().size();
        return oss.str();
    }

    void NextPage()
    {
        if (current_page < (int)book->GetPages().size() - 1)
            current_page++;
    }

    void PreviousPage()
    {
        if (current_page > 0)
            current_page--;
    }
};

/** @class User
 *  @brief Represents a system user (admin or customer).
 */
class User
{
private:
    string user_name;
    string password;
    string name;
    string email;
    bool is_library_admin;
    vector<BookReadingSession *> reading_sessions;

public:
    User(const User &) = delete;
    void operator=(const User &) = delete;

    User() { is_library_admin = false; }

    ~User()
    {
        cout << "Destructor User\n";
        for (auto &session : reading_sessions)
            delete session;
        reading_sessions.clear();
    }

    string ToString() const
    {
        ostringstream oss;
        oss << "Name: " << user_name;
        if (IsLibraryAdmin())
            oss << " | Admin";
        oss << "\n";
        oss << "Email: " << email << "\n";
        oss << "User name: " << user_name << "\n";
        return oss.str();
    }

    void Read(const string &user_name)
    {
        SetUserName(user_name);

        string str;
        cout << "Enter password (no spaces): ";
        cin >> str;
        SetPassword(str);

        cout << "Enter name (no spaces): ";
        cin >> str;
        SetName(str);

        cout << "Enter email (no spaces): ";
        cin >> str;
        SetEmail(str);
    }

    const string &GetEmail() const { return email; }
    const string &GetName() const { return name; }
    const string &GetPassword() const { return password; }
    const string &GetUserName() const { return user_name; }
    bool IsLibraryAdmin() const { return is_library_admin; }
    const vector<BookReadingSession *> &GetReadingSessions() const
    {
        return reading_sessions;
    }

    void SetEmail(const string &email) { this->email = email; }
    void SetName(const string &name) { this->name = name; }
    void SetPassword(const string &password) { this->password = password; }
    void SetUserName(const string &userName) { user_name = userName; }
    void SetIsLibraryAdmin(bool isLibraryAdmin) { is_library_admin = isLibraryAdmin; }

    BookReadingSession *AddReadingSession(Book *book)
    {
        BookReadingSession *session = new BookReadingSession(book);
        reading_sessions.push_back(session);
        return session;
    }
};

/** @class UsersManager
 *  @brief Manages all users and current login session.
 */
class UsersManager
{
private:
    User *current_user{nullptr};
    map<string, User *> userame_userobject_map;

    void FreeLoadedData()
    {
        for (auto pair : userame_userobject_map)
        {
            delete pair.second;
        }
        userame_userobject_map.clear();
        current_user = nullptr;
    }

public:
    UsersManager() = default;

    ~UsersManager()
    {
        cout << "Destuctor: UsersManager\n";
        FreeLoadedData();
    }

    UsersManager(const UsersManager &) = delete;
    void operator=(const UsersManager &) = delete;

    void LoadDatabase()
    {
        if (userame_userobject_map.size() > 0)
            return;

        cout << "UsersManager: LoadDatabase\n";
        FreeLoadedData();

        // Admin: rahat
        User *user1 = new User();
        user1->SetUserName("rahat");
        user1->SetPassword("111");
        user1->SetEmail("rahat@gmail.com");
        user1->SetIsLibraryAdmin(true);
        user1->SetName("Ualiur Rahman Rahat");
        userame_userobject_map[user1->GetUserName()] = user1;

        // Customer: tamanna
        User *user2 = new User();
        user2->SetUserName("tamanna");
        user2->SetPassword("222");
        user2->SetEmail("tamanna@gmail.com");
        user2->SetIsLibraryAdmin(false);
        user2->SetName("Kamrunnaher Tamanna");
        userame_userobject_map[user2->GetUserName()] = user2;
    }

    void AccessSystem()
    {
        int choice = ShowReadMenu({"Login", "Sign Up"});
        if (choice == 1)
            DoLogin();
        else
            DoSignUp();
    }

    void DoLogin()
    {
        LoadDatabase();

        while (true)
        {
            string user_name, pass;
            cout << "Enter user name (no spaces): ";
            cin >> user_name;
            cout << "Enter password (no spaces): ";
            cin >> pass;

            auto it = userame_userobject_map.find(user_name);
            if (it == userame_userobject_map.end())
            {
                cout << "\nInvalid user name or password. Try again\n\n";
                continue;
            }

            User *user_exist = it->second;
            if (pass != user_exist->GetPassword())
            {
                cout << "\nInvalid user name or password. Try again\n\n";
                continue;
            }

            current_user = user_exist;
            break;
        }
    }

    void DoSignUp()
    {
        string user_name;
        while (true)
        {
            cout << "Enter user name (No spaces): ";
            cin >> user_name;

            if (userame_userobject_map.count(user_name))
                cout << "Already used. Try again\n";
            else
                break;
        }
        current_user = new User();
        current_user->Read(user_name);
        userame_userobject_map[current_user->GetUserName()] = current_user;
    }

    BookReadingSession *AddReadingSession(Book *book)
    {
        return current_user->AddReadingSession(book);
    }

    const User *GetCurrentUser() const { return current_user; }
};

/** @class BooksManager
 *  @brief Manages all books in the system.
 */
class BooksManager
{
private:
    map<string, Book *> isbn_to_book_map;

    void FreeLoadedData()
    {
        for (auto pair : isbn_to_book_map)
        {
            delete pair.second;
        }
        isbn_to_book_map.clear();
    }

public:
    BooksManager() = default;

    void LoadDatabase()
    {
        cout << "BooksManager: LoadDatabase\n";
        FreeLoadedData();

        Book *book1 = new Book();
        book1->SetIsbn("00001");
        book1->SetAuthor("Rahat");
        book1->SetTitle("C++ how to program");
        book1->SetPages({"A C++", "B C++", "C C++", "D C++", "E C++"});
        AddBook(book1);

        Book *book2 = new Book();
        book2->SetIsbn("00002");
        book2->SetAuthor("Morad");
        book2->SetTitle("Intro to algo");
        book2->SetPages({"A Algo", "B Algo", "C Algo", "D Algo", "E "});
        AddBook(book2);

        Book *book3 = new Book();
        book3->SetIsbn("00003");
        book3->SetAuthor("Morad");
        book3->SetTitle("Data Structures in C++");
        book3->SetPages({"A Data", "B Data", "C Data", "D Data", "E Data"});
        AddBook(book3);
    }

    ~BooksManager()
    {
        cout << "Destuctor: BooksManager\n";
        FreeLoadedData();
    }

    BooksManager(const BooksManager &) = delete;
    void operator=(const BooksManager &) = delete;

    void AddBook(Book *book) { isbn_to_book_map[book->GetIsbn()] = book; }
    const map<string, Book *> &GetIsbnToBookMap() const { return isbn_to_book_map; }
};

/** @class UserView
 *  @brief UI for regular users (customers).
 */
class UserView
{
private:
    UsersManager &users_manager;
    BooksManager &books_manager;

public:
    UserView(UsersManager &um, BooksManager &bm)
        : users_manager(um), books_manager(bm) {}

    void Display()
    {
        const User *user = users_manager.GetCurrentUser();
        cout << "\n\nHello " << user->GetName() << " | User View\n";

        vector<string> menu = {
            "View Profile",
            "List & Select from My Reading History",
            "List & Select from Available Books",
            "Logout"};

        while (true)
        {
            int choice = ShowReadMenu(menu);
            if (choice == 1)
                ViewProfile();
            else if (choice == 2)
                ListReadingHistory();
            else if (choice == 3)
                ListAvailableBooks();
            else
                break;
        }
    }

    void ViewProfile()
    {
        cout << "\n"
             << users_manager.GetCurrentUser()->ToString() << "\n";
    }

    void DisplaySession(BookReadingSession *session)
    {
        vector<string> menu = {"Next Page", "Previous Page", "Stop Reading"};

        while (true)
        {
            cout << "Current Page: " << session->PageIdxStr() << "\n";
            cout << session->GetCurrentPageContent() << "\n";

            int choice = ShowReadMenu(menu);
            if (choice == 1)
                session->NextPage();
            else if (choice == 2)
                session->PreviousPage();
            else
                break;
        }
        session->ResetLastAccessDate();
    }

    void ListReadingHistory()
    {
        const auto &sessions = users_manager.GetCurrentUser()->GetReadingSessions();
        int idx = 0;
        for (auto &session : sessions)
        {
            cout << ++idx << ": " << session->ToString() << "\n";
        }

        if (idx == 0)
        {
            cout << "\nNo history. List books and start having fun\n";
            return;
        }

        cout << "\nWhich session to open?: ";
        int choice = ReadInt(1, idx);
        DisplaySession(sessions[choice - 1]);
    }

    void ListAvailableBooks()
    {
        const map<string, Book *> &mp = books_manager.GetIsbnToBookMap();
        cout << "\nOur current book collection:\n";
        int idx = 0;
        for (const auto &pair : mp)
        {
            cout << "\t" << ++idx << " " << pair.second->ToString() << "\n";
        }

        cout << "\nWhich book to read?: ";
        int choice = ReadInt(1, idx);

        idx = 0;
        for (const auto &pair : mp)
        {
            if (++idx == choice)
            {
                BookReadingSession *session = users_manager.AddReadingSession(pair.second);
                DisplaySession(session);
                break;
            }
        }
    }
};

/** @class AdminView
 *  @brief UI for admin users.
 */
class AdminView
{
private:
    UsersManager &users_manager;
    BooksManager &books_manager;

public:
    AdminView(UsersManager &um, BooksManager &bm)
        : users_manager(um), books_manager(bm) {}

    void Display()
    {
        const User *user = users_manager.GetCurrentUser();
        cout << "\n\nHello " << user->GetName() << " | Admin View\n";

        vector<string> menu = {"View Profile", "Add Book", "Logout"};

        while (true)
        {
            int choice = ShowReadMenu(menu);
            if (choice == 1)
                ViewProfile();
            else if (choice == 2)
                AddBook();
            else
                break;
        }
    }

    void ViewProfile()
    {
        cout << "\n"
             << users_manager.GetCurrentUser()->ToString() << "\n";
    }

    void AddBook()
    {
        Book *book = new Book();
        book->Read();
        books_manager.AddBook(book);
    }
};

/** @class OnlineReaderSystem
 *  @brief Main system orchestrator.
 */
class OnlineReaderSystem
{
private:
    BooksManager *books_manager;
    UsersManager *users_manager;

    void LoadDatabase()
    {
        users_manager->LoadDatabase();
        books_manager->LoadDatabase();
    }

public:
    OnlineReaderSystem()
        : books_manager(new BooksManager()), users_manager(new UsersManager()) {}

    ~OnlineReaderSystem()
    {
        cout << "Destuctor: OnlineReaderSystem\n";
        delete books_manager;
        delete users_manager;
    }

    void Run()
    {
        LoadDatabase();

        while (true)
        {
            users_manager->AccessSystem();

            if (users_manager->GetCurrentUser()->IsLibraryAdmin())
            {
                AdminView view(*users_manager, *books_manager);
                view.Display();
            }
            else
            {
                UserView view(*users_manager, *books_manager);
                view.Display();
            }
        }
    }
};

int main()
{
    OnlineReaderSystem site;
    site.Run();
    return 0;
}