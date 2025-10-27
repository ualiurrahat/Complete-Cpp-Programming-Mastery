# 📚 Library Management System (C++ Console Project)

## 🧾 Project Overview

This is a **console-based Library Management System** written in **C++**.  
It is a simplified educational version of a library system that allows an admin to:

- Add and search books
- Manage users
- Record book borrowing and returning
- List all books and users in an organized way

This project is ideal for **beginners in Object-Oriented Programming (OOP)** who want to learn how to design and implement a system using **structs, arrays, and control flow in C++**.

---

## 🧠 Project Background

Libraries maintain systems that store information about books, users, and borrowing activity.  
This project replicates a **basic version** of such systems to demonstrate how core data structures and control logic work in practice.

**Key ideas implemented:**

- Each **Book** has:
  - `id` (integer)
  - `name` (string, no spaces for simplicity)
  - `total_quantity` (number of copies available in the library)
  - `total_borrowed` (number of copies currently borrowed)
- Each **User** has:
  - `id` (integer)
  - `name` (string, no spaces)
  - A list of borrowed book IDs

The system does not require login. All operations are performed by an **admin** through a **menu-driven console interface**.

---

## ⚙️ Features

### 📘 Book Operations

1. **Add a Book**  
   Admin can add new books by providing:

   - Book ID
   - Book Name
   - Total Quantity

2. **Search Books by Prefix**  
   Allows searching for books whose names start with a given prefix.  
   Example:

   ```
   Prefix: Cpp
   Result: CppHowToProgram, CppForDummies, CppForAdvancedLevels
   ```

3. **List Books (Sorted)**

   - **By ID** → Ascending order of IDs
   - **By Name** → Alphabetical order

4. **Show Borrowers of a Book**  
   Given a book name, the system lists all users who borrowed copies of it.

---

### 👤 User Operations

1. **Add a User**  
   Adds a new user by reading their name and national ID.

2. **Borrow a Book**  
   A user can borrow a book if there are available copies.

   - Decreases the available quantity of the book.
   - Records the borrow under the user’s name.

3. **Return a Book**

   - Marks that the user returned a copy.
   - Increases the available quantity of the book.

4. **List All Users**  
   Displays all registered users and the books they borrowed.

---

## 🧩 System Menu

The system operates using a looped menu interface:

```
1) add_book
2) search_books_by_prefix
3) print_who_borrowed_book_by_name
4) print_library_by_id
5) print_library_by_name
6) add_user
7) user_borrow_book
8) user_return_book
9) print_users
10) Exit
```

After each operation, the main menu appears again until the admin chooses option `10`.

---

## 🏗️ System Design

### Data Structures Used

| Entity         | Data Type              | Description                                                  |
| -------------- | ---------------------- | ------------------------------------------------------------ |
| Book           | `struct Book`          | Holds book id, name, total quantity, and borrowed count      |
| User           | `struct User`          | Holds user id, name, and list of borrowed book IDs           |
| Library System | `struct LibrarySystem` | Manages arrays of books and users and all related operations |

### Constants

```cpp
const int MAX_BOOKS = 100;  // maximum number of books
const int MAX_USERS = 100;  // maximum number of users
```

### Sorting

Sorting is done using `std::sort` with custom comparators:

- `cmpBookById`
- `cmpBookByName`

---

## 💻 Example Input and Output

### Example Input

```
1 100 math4 3
1 101 math2 5
1 102 math1 4
1 103 math3 2
1 201 prog1 5
1 202 prog2 3
4
6 mostafa 30301
6 ali 50501
7 mostafa math1
7 ali math2
9
10
```

### Example Output

```
id = 100 name = math4 total_quantity = 3 total_borrowed = 0
id = 101 name = math2 total_quantity = 5 total_borrowed = 1
user mostafa id 30301 borrowed books ids: 102
user ali id 50501 borrowed books ids: 101
```

---

## 🧑‍🏫 Educational Goals

This project helps beginners learn:

- Basic **C++ syntax** and **data structures**
- **Structs** and how to use them to group related data
- **Function documentation** and clean commenting
- How to implement **menus and loops** in console programs
- How to use **arrays, sorting, and simple searching**
- How to logically model relationships (Book–User borrowing system)

---

## 🧱 Technologies Used

- **Language:** C++
- **Paradigm:** Structured + Object-Oriented Programming concepts
- **Compiler:** Any standard C++17 or later (e.g., g++, clang++)
- **Environment:** Console-based (no GUI or database used)

---

## 🧮 Complexity Analysis

| Operation                  | Time Complexity | Space Complexity |
| -------------------------- | --------------- | ---------------- |
| Add Book / Add User        | O(1)            | O(1)             |
| Search Books by Prefix     | O(n \* m)       | O(1)             |
| Sort Books (by ID or Name) | O(n log n)      | O(1)             |
| Borrow / Return Book       | O(n)            | O(1)             |
| Print Borrowers / Users    | O(n)            | O(1)             |

Where `n` = number of books or users, and `m` = prefix length.

---

## 🚀 How to Run

### 1️⃣ Compile

Use any standard C++ compiler:

```bash
g++ 02_librarySystem.cpp -o library
```

### 2️⃣ Run

```bash
./library
```

### 3️⃣ Follow Menu

Use numeric options to perform operations interactively.

---

## 📦 Project Structure

```
📁 Project 02 - Libray System
│
├── 📄 02_librarySystem.cpp   # Main source code (single-file implementation)
├── 📄 README.md            # Documentation (this file)
```

---

## 🧑‍💻 Author

**Md. Ualiur Rahman Rahat**  
🎓 Graduated in B.Sc Engineering in Electrical and Electronic Engineering  
📚 Student at the University of the People (B.Sc. in Computer Science)  
💡 Passionate about Software Engineering, C++, and System Design

---

## 🪪 License

This project is released under the **MIT License**.  
You are free to use, modify, and distribute it for educational purposes with attribution.

---

## 🏁 Final Notes

- The project uses **arrays and simple logic** for educational clarity.
- For advanced versions, you can:
  - Use `std::vector` instead of fixed arrays
  - Store data in text files for persistence
  - Allow spaces in book/user names
  - Implement search by ID and full user reports

This project provides a strong foundation for understanding the basics of C++ systems programming and can easily be extended into a more realistic library management software.
