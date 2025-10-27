# AskMe — File-Based Q&A System (C++)

## Project Overview

**AskMe** is a console-based Q&A platform implemented in C++.  
It is inspired by social Q&A systems and is designed as an educational project to teach file I/O, data modeling, and basic application flow.

Data persistence is handled using two text files (CSV-like):

- `users.txt` — stores registered users (one line per user)
- `questions.txt` — stores questions and answers (one line per question)

This version of the project is corrected and commented for clarity and learning.

---

## Features

- Register new users (Sign Up)
- Login / Logout
- Ask questions to other users (optionally anonymous)
- Threaded questions (a question can be a reply to a parent question)
- Answer questions you received
- Delete your questions (deleting a parent removes the entire thread)
- View:
  - Questions **To Me**
  - Questions **From Me**
  - Public **Feed** (answered questions)
- Simple in-memory maps, and file persistence using text files

---

## Data Format (CSV)

### users.txt (6 fields)

```
user_id,user_name,password,name,email,allow_anonymous_questions
```

### questions.txt (7 fields)

```
question_id,parent_question_id,from_user_id,to_user_id,is_anonymous,question_text,answer_text
```

**Notes**

- Fields are expected to be single tokens without commas (this keeps parsing simple).
- `parent_question_id` is `-1` for root questions.
- `is_anonymous` is `1` (anonymous) or `0` (not anonymous).

---

## How to compile

Requires a standard C++17 compatible compiler.

```bash
g++ 03_AskMe.cpp -o askme
```

Then run:

```bash
./askme
```

---

## Example usage (interactive)

1. Start program:

   - Choose `Sign Up` to create a user.
   - Choose `Login` to authenticate.

2. Once logged in:

   - Use the menu to print questions to you, from you, answer, delete, ask new questions, or view feed.

3. When asking:
   - You can choose to attach your question to an existing thread (enter parent id) or create a new root question (`-1`).

---

## Implementation notes

- The app loads all users and questions into memory on each relevant operation to keep behavior clear.
- When updating (e.g., after answering or deleting), the program writes the entire questions/users list back to the corresponding file (overwrite).
- For classroom use this last-write-wins strategy is acceptable. For real-world systems use databases and proper concurrency control.

---

## Tips for testing

- Create `users.txt` and `questions.txt` in the same folder as the executable. If they don't exist the program will start with empty data and print a warning.
- Use small integer IDs only if you create files manually — when the program creates users/questions it will assign unique IDs automatically.
- To test scripted input, you can redirect input from a text file containing a sequence of menu choices and the required data tokens:

```bash
./askme < test_input.txt
```

---

## License

MIT — feel free to reuse and adapt for learning and small projects. Please include attribution if you publish derivatives.

---

## Contact / Author

Project updated and documented for clarity by: **Md. Ualiur Rahman Rahat**
