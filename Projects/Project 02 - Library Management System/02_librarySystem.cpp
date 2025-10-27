/**
 * Library System Project
 * ----------------------
 * Description (full):
 * This is a console-based simple Library Management System implemented in C++.
 * The system is intended for an admin user (no login required) to perform common
 * library operations such as adding books, searching books by prefix, listing
 * books sorted by id or name, adding users, borrowing/returning book copies,
 * and listing which users borrowed a specific book.
 *
 * Background notes (explanation):
 * - Every book has an integer id, a string name (no spaces expected in this
 *   simple console input), a total number of copies (total_quantity), and a
 *   current borrowed counter (total_borrowed).
 * - Users have an integer id and a name. Each user can borrow multiple books,
 *   subject to available copies for each book.
 * - When a user borrows a book, we decrement the available copies (conceptually
 *   total_quantity - total_borrowed). When the user returns the book, we
 *   increment the returned count.
 * - Searching supports prefixes: e.g. query "CppFo" matches "CppForDummies".
 * - Listing supports sorting either by book id or by book name.
 *
 * Notes for students and reviewers:
 * - The code uses only necessary headers and keeps logic self-contained to
 *   remain easy to read and follow.
 * - Extensive inline comments are provided so that a beginner can follow the
 *   flow of data and control.
 *
 * Constraints and assumptions for this console assignment:
 * - Maximum books and users are defined by constants MAX_BOOKS and MAX_USERS
 *   to keep the program simple (no file or database persistence in this demo).
 * - Book and user names should be single tokens (no spaces). For a production
 *   app, use getline() and better parsing.
 *
 * Author: Student (example project)
 * Date: 2025-10-27
 */

// Required standard headers only
#include <iostream>   // for input / output streams
#include <string>     // for std::string
#include <algorithm>  // for std::sort
#include <cassert>    // for assert()

using namespace std; // Allowed per project instruction (keep code concise)

// Project limits (small for classroom/demo purposes)
const int MAX_BOOKS = 100; // maximum number of books the system can hold
const int MAX_USERS = 100; // maximum number of users the system can hold

/**
 * struct Book
 * ------------
 * Represents a book in the library.
 */
struct Book {
    int id;                 // unique integer identifier for the book
    string name;            // book name (single token expected)
    int totalQuantity;      // total copies that the library owns
    int totalBorrowed;      // how many copies currently borrowed

    // Default constructor initializes a "blank" book
    Book() : id(-1), name(""), totalQuantity(0), totalBorrowed(0) {}

    /**
     * read()
     * Reads book information from standard input.
     * Parameters: none
     * Returns: void
     * Side effects: reads id, name and totalQuantity from cin and sets
     * totalBorrowed to 0 (freshly added book has no borrowed copies yet).
     */
    void read() {
        // Prompt the admin for book information
        cout << "Enter book info: id & name & total quantity: ";

        // Read values from the console. Note: using >> reads a single token for name
        cin >> id >> name >> totalQuantity;

        // Reset borrowed counter for a newly added book
        totalBorrowed = 0;
    }

    /**
     * borrow()
     * Attempts to borrow one copy of this book.
     * Parameters:
     *   - userId: the id of the user who wants to borrow (unused for internal
     *             bookkeeping here but kept to reflect the interface)
     * Returns: bool
     *   - true  => borrowing succeeded (a copy was available and totalBorrowed++).
     *   - false => no available copies (totalQuantity - totalBorrowed == 0).
     * Side effects: increments totalBorrowed when successful.
     */
    bool borrow(int /*userId*/) {
        // Compute available copies: totalQuantity - totalBorrowed
        if (totalQuantity - totalBorrowed == 0)
            return false; // no copies available

        // A copy is available: increase borrowed counter and return success
        ++totalBorrowed;
        return true;
    }

    /**
     * returnCopy()
     * Records that one copy was returned.
     * Parameters: none
     * Returns: void
     * Side effects: decrements totalBorrowed. Uses assert() to guarantee there
     * are borrowed copies to return (programmer error otherwise).
     */
    void returnCopy() {
        // Ensure we don't return more copies than borrowed
        assert(totalBorrowed > 0);
        --totalBorrowed;
    }

    /**
     * hasPrefix()
     * Checks if the book name starts with the given prefix string.
     * Parameters:
     *   - prefix: string prefix to check
     * Returns: bool -> true if the book name starts with prefix, false otherwise
     */
    bool hasPrefix(const string &prefix) const {
        // If prefix is longer than the name, it cannot match
        if (name.size() < prefix.size())
            return false;

        // Compare characters one-by-one (prefix length)
        for (size_t i = 0; i < prefix.size(); ++i) {
            if (prefix[i] != name[i])
                return false; // mismatch found
        }
        return true; // all prefix chars matched
    }

    /**
     * print()
     * Prints the book fields in a readable format.
     * Parameters: none
     * Returns: void
     */
    void print() const {
        cout << "id = " << id
             << " name = " << name
             << " total_quantity = " << totalQuantity
             << " total_borrowed = " << totalBorrowed << "\n";
    }
};

// Comparison helpers used by std::sort when listing books
bool cmpBookByName(const Book &a, const Book &b) { return a.name < b.name; }
bool cmpBookById(const Book &a, const Book &b)   { return a.id < b.id; }

/**
 * struct User
 * -----------
 * Represents a library user (borrower). Each user stores a small list of
 * borrowed book ids. For simplicity we keep an array of fixed size MAX_BOOKS
 * per user in this demo. In real systems use dynamic containers and persist
 * data to a database.
 */
struct User {
    int id;                         // unique integer id for the user
    string name;                    // user name (single token expected)
    int borrowedBookIds[MAX_BOOKS]; // fixed-size array of borrowed book ids
    int len;                        // current number of borrowed books

    // Default constructor - initialize user as empty
    User() : id(-1), name(""), len(0) {
        // No need to initialize borrowedBookIds values; len controls used slots
    }

    /**
     * read()
     * Reads user information (name and id) from standard input.
     * Parameters: none
     * Returns: void
     */
    void read() {
        cout << "Enter user name & national id: ";
        cin >> name >> id; // read two tokens: name and id
    }

    /**
     * borrow()
     * Marks that this user borrowed a book with id bookId.
     * Parameters:
     *   - bookId: integer id of the borrowed book
     * Returns: void
     * Side effects: stores bookId in the user's array and increases len.
     * Note: no duplicate-checking is performed here (a user could borrow the
     * same book multiple times if allowed by the library policy).
     */
    void borrow(int bookId) {
        // Store the borrowed book id at the next free slot
        borrowedBookIds[len++] = bookId;
    }

    /**
     * returnCopy()
     * Marks that this user returned one copy of the given book.
     * Parameters:
     *   - bookId: integer id of the returned book
     * Returns: void
     * Side effects: removes the first matching bookId from the array and
     * decrements len. If the user didn't borrow that book, prints a message.
     */
    void returnCopy(int bookId) {
        bool removed = false; // flag to indicate if we found the book to remove

        // Linear search for the bookId in the borrowed list
        for (int i = 0; i < len; ++i) {
            if (borrowedBookIds[i] == bookId) {
                // Shift elements left to overwrite the removed element
                for (int j = i + 1; j < len; ++j)
                    borrowedBookIds[j - 1] = borrowedBookIds[j];

                // Adjust length and set flag
                --len;
                removed = true;
                break; // remove only one copy (if user had multiple)
            }
        }

        // If the book was not found in the user's borrowed list, notify admin
        if (!removed)
            cout << "User " << name << " never borrowed book id " << bookId << "\n";
    }

    /**
     * isBorrowed()
     * Checks whether the user currently has the given book id in their
     * borrowed list.
     * Parameters:
     *   - bookId: integer id to look for
     * Returns: bool (true if the user has borrowed this book)
     */
    bool isBorrowed(int bookId) const {
        for (int i = 0; i < len; ++i) {
            if (borrowedBookIds[i] == bookId)
                return true;
        }
        return false;
    }

    /**
     * print()
     * Prints user information and the (sorted) list of borrowed book ids.
     * Parameters: none
     * Returns: void
     */
    void print() const {
        // We cannot call sort() on a const object; make a local copy to sort
        int copyArr[MAX_BOOKS];
        for (int i = 0; i < len; ++i)
            copyArr[i] = borrowedBookIds[i];

        // Sort the local copy to present them in increasing order
        sort(copyArr, copyArr + len);

        // Print user core info and the borrowed ids list
        cout << "user " << name << " id " << id << " borrowed books ids: ";
        for (int i = 0; i < len; ++i)
            cout << copyArr[i] << " ";
        cout << "\n";
    }
};

/**
 * class LibrarySystem
 * -------------------
 * Encapsulates the entire system: arrays of books and users and all
 * operations exposed to the admin.
 */
struct LibrarySystem {
    int totalBooks;     // current number of books stored
    Book books[MAX_BOOKS];

    int totalUsers;     // current number of users stored
    User users[MAX_USERS];

    // Constructor initializes counters
    LibrarySystem() : totalBooks(0), totalUsers(0) {}

    /**
     * run()
     * Main loop of the console application which repeatedly shows the menu,
     * reads the admin choice and executes the requested operation.
     * Parameters: none
     * Returns: void
     */
    void run() {
        while (true) {
            int choice = menu(); // show menu and read choice

            if (choice == 1) addBook();
            else if (choice == 2) searchBooksByPrefix();
            else if (choice == 3) printWhoBorrowedBookByName();
            else if (choice == 4) printLibraryById();
            else if (choice == 5) printLibraryByName();
            else if (choice == 6) addUser();
            else if (choice == 7) userBorrowBook();
            else if (choice == 8) userReturnBook();
            else if (choice == 9) printUsers();
            else break; // any other choice exits the loop and program
        }
    }

    /**
     * menu()
     * Displays the main menu options and reads a validated choice from the
     * admin. It repeats prompting until a valid integer in range is provided.
     * Parameters: none
     * Returns: int -> the chosen menu item (1..10)
     */
    int menu() {
        int choice = -1;

        // Keep prompting until a valid choice is entered
        while (choice == -1) {
            cout << "\nLibrary Menu:\n";
            cout << "1) add_book\n";
            cout << "2) search_books_by_prefix\n";
            cout << "3) print_who_borrowed_book_by_name\n";
            cout << "4) print_library_by_id\n";
            cout << "5) print_library_by_name\n";
            cout << "6) add_user\n";
            cout << "7) user_borrow_book\n";
            cout << "8) user_return_book\n";
            cout << "9) print_users\n";
            cout << "10) Exit\n";

            cout << "\nEnter your menu choice [1 - 10]: ";
            cin >> choice;

            // Validate the choice range
            if (!(1 <= choice && choice <= 10)) {
                cout << "Invalid choice. Try again\n";
                choice = -1; // reset so loop continues
            }
        }

        return choice;
    }

    /**
     * addBook()
     * Adds a new book to the system by reading its info and storing it in the
     * next free slot. No duplicate checking is performed for simplicity.
     * Parameters: none
     * Returns: void
     */
    void addBook() {
        // Safety check: prevent exceeding MAX_BOOKS
        if (totalBooks >= MAX_BOOKS) {
            cout << "Cannot add more books: storage full\n";
            return;
        }

        // Use the Book::read() helper to get book fields from admin
        books[totalBooks++].read();
    }

    /**
     * searchBooksByPrefix()
     * Prompts the admin for a prefix and prints book names that start with it.
     * Parameters: none
     * Returns: void
     */
    void searchBooksByPrefix() {
        cout << "Enter book name prefix: ";
        string prefix;
        cin >> prefix; // read prefix token

        int cnt = 0; // count matches to inform if no results
        for (int i = 0; i < totalBooks; ++i) {
            if (books[i].hasPrefix(prefix)) {
                cout << books[i].name << "\n"; // print matching name
                ++cnt;
            }
        }

        if (!cnt) cout << "No books with such prefix\n";
    }

    /**
     * addUser()
     * Adds a new user to the system by reading their name and id.
     * Parameters: none
     * Returns: void
     */
    void addUser() {
        if (totalUsers >= MAX_USERS) {
            cout << "Cannot add more users: storage full\n";
            return;
        }

        users[totalUsers++].read();
    }

    /**
     * findBookIdxByName()
     * Finds the index of a book by its exact name (not prefix).
     * Parameters:
     *  - name: exact book name to search for
     * Returns: int -> index in books[] (0..totalBooks-1) or -1 if not found
     */
    int findBookIdxByName(const string &name) const {
        for (int i = 0; i < totalBooks; ++i) {
            if (name == books[i].name) return i;
        }
        return -1; // not found
    }

    /**
     * findUserIdxByName()
     * Finds the index of a user by exact name.
     * Parameters:
     *  - name: exact user name
     * Returns: int -> index in users[] or -1 if not found
     */
    int findUserIdxByName(const string &name) const {
        for (int i = 0; i < totalUsers; ++i) {
            if (name == users[i].name) return i;
        }
        return -1;
    }

    /**
     * readUserNameAndBookName()
     * Helper that prompts the admin to enter user name and book name in one
     * line, validates them and returns their indices if valid.
     * Parameters:
     *  - userIdx: reference int to store found user index
     *  - bookIdx: reference int to store found book index
     *  - trials: number of attempts allowed before failing (default 3)
     * Returns: bool -> true if both user and book were found, false otherwise
     */
    bool readUserNameAndBookName(int &userIdx, int &bookIdx, int trials = 3) {
        string userName;
        string bookName;

        while (trials--) {
            cout << "Enter user name and book name: ";
            cin >> userName >> bookName; // read two tokens

            userIdx = findUserIdxByName(userName);
            if (userIdx == -1) {
                cout << "Invalid user name. Try again\n";
                continue; // prompt again
            }

            bookIdx = findBookIdxByName(bookName);
            if (bookIdx == -1) {
                cout << "Invalid book name. Try again\n";
                continue; // prompt again
            }

            // both valid
            return true;
        }

        cout << "You did several trials! Try later." << endl;
        return false; // failed to get valid user+book within attempts
    }

    /**
     * userBorrowBook()
     * Admin operation to borrow a book on behalf of a user. If the book has
     * available copies, we record the borrow and decrease availability.
     * Parameters: none
     * Returns: void
     */
    void userBorrowBook() {
        int userIdx, bookIdx;

        // read and validate user+book names
        if (!readUserNameAndBookName(userIdx, bookIdx))
            return; // validation failed

        int userId = users[userIdx].id; // user id used internally
        int bookId = books[bookIdx].id; // book id used to store in user record

        // Try to borrow a copy from the book object
        if (!books[bookIdx].borrow(userId))
            cout << "No more copies available right now\n";
        else
            users[userIdx].borrow(bookId); // record the book id for the user
    }

    /**
     * userReturnBook()
     * Admin operation to record a return from a user for a specific book.
     * Parameters: none
     * Returns: void
     */
    void userReturnBook() {
        int userIdx, bookIdx;

        if (!readUserNameAndBookName(userIdx, bookIdx))
            return; // validation failed

        int bookId = books[bookIdx].id;

        // Update the book and user data structures accordingly
        books[bookIdx].returnCopy();      // decrement borrowed counter for the book
        users[userIdx].returnCopy(bookId); // remove book from user's borrowed list
    }

    /**
     * printLibraryById()
     * Sorts the books array by id and prints the full book information.
     * Parameters: none
     * Returns: void
     * Complexity: O(totalBooks * log(totalBooks)) due to sort.
     */
    void printLibraryById() {
        // Sort only the portion of the array that is used by the system
        sort(books, books + totalBooks, cmpBookById);

        cout << "\n";
        for (int i = 0; i < totalBooks; ++i)
            books[i].print();
    }

    /**
     * printLibraryByName()
     * Sorts books by name and prints them. Same complexity note as printLibraryById.
     */
    void printLibraryByName() {
        sort(books, books + totalBooks, cmpBookByName);

        cout << "\n";
        for (int i = 0; i < totalBooks; ++i)
            books[i].print();
    }

    /**
     * printUsers()
     * Prints all users and the ids of the books they borrowed (sorted in output).
     * Parameters: none
     * Returns: void
     */
    void printUsers() {
        cout << "\n";
        for (int i = 0; i < totalUsers; ++i)
            users[i].print();
    }

    /**
     * printWhoBorrowedBookByName()
     * Given an exact book name, prints the names of users who currently have
     * borrowed copies of that book.
     * Parameters: none
     * Returns: void
     */
    void printWhoBorrowedBookByName() {
        string bookName;
        cout << "Enter book name: ";
        cin >> bookName; // exact match expected for simplicity

        int bookIdx = findBookIdxByName(bookName);
        if (bookIdx == -1) {
            cout << "Invalid book name." << endl;
            return;
        }

        int bookId = books[bookIdx].id;

        // If no copies are borrowed, inform the admin
        if (books[bookIdx].totalBorrowed == 0) {
            cout << "No borrowed copies\n";
            return;
        }

        // Otherwise list all users who have this book id in their borrowed list
        for (int i = 0; i < totalUsers; ++i) {
            if (users[i].isBorrowed(bookId))
                cout << users[i].name << "\n";
        }
    }
};

/**
 * main()
 * ----
 * Demonstrates running the LibrarySystem console application.
 * We create a LibrarySystem instance and call run(). The run loop handles
 * interactions with the admin through standard input/output.
 *
 * Note: For classroom testing you can use input redirection (e.g. ./a.out < in.txt)
 * where in.txt contains a sequence of menu operations (example provided below
 * in the comment block). The program uses console prompts - so when using
 * redirected input the prompts will still be printed but input will come from
 * the file.
 */
int main() {
    // Create the library system object which stores books and users
    LibrarySystem library;

    // Start the interactive console application. The program will continue
    // until the admin selects the "Exit" menu option.
    library.run();

    return 0;
}

/*
Example input sequence (tokens separated by whitespace) and explanation:
-----------------------------------------------------------
# Add several books (menu=1):
1 100 math4 3
1 101 math2 5
1 102 math1 4
1 103 math3 2
1 201 prog1 5
1 202 prog2 3

# Print library by id (4) then by name (5)
4
5

# Add users (6):
6 mostafa 30301
6 ali 50501
6 noha 70701
6 ashraf 90901

# Borrowing operations (7): userName bookName
7 mostafa math1
7 mostafa math2
7 mostafa math3
7 ali math1
7 ali math2
7 noha math1
7 noha math3
7 noha prog2

# Print books and users
4 (print library by id)
9 (print users)

# Search by prefix (2):
2 ma
2 pro
2 machine

# List who borrowed a particular book (3):
3 math1
3 math2
3 machine

# More prints and a return (8):
4
9
8 mostafa math1  (mostafa returns math1)
4
9

# Exit (10)
10
-----------------------------------------------------------
Expected behaviour:
- Borrow operations reduce available copies and attach the book id to the user.
- Return operations increase available copies and remove the book id from the user.
- Search prefix matches correct book names.
*/
