# AskMe v0.4 — File-Based Q&A System (C++)

## Project Overview

AskMe v0.4 is an upgraded, cleaned, and well-documented console-based Q&A platform written in C++.  
It stores data using two CSV-like text files in the program working directory:

- `users.txt` — registered users (one line per user)
- `questions.txt` — questions and answers (one line per question)

This version fixes bugs from previous iterations, improves input validation, and provides clearer code organization and comments for learning.

---

## Features

- Sign Up / Login
- Ask questions to other users (anonymous or named)
- Threaded conversations: questions can be replies to parent questions
- Answer or delete questions (only by the receiver)
- View:
  - Questions **To Me**
  - Questions **From Me**
  - Public **Feed** (answered questions)
- Simple file-based persistence and in-memory maps for fast access

---

## File Formats (CSV)

### users.txt (6 fields)
```
user_id,user_name,password,name,email,allow_anonymous_questions
```

Example:
```
13,mostafa,111,mostafa_saad_ibrahim,mostafa@gmail.com,1
11,noha,222,noha_salah,nono171@gmail.com,0
45,ali,333,ali_wael,wael@gmail.com,0
```

### questions.txt (7 fields)
```
question_id,parent_question_id,from_user_id,to_user_id,is_anonymous,question_text,answer_text
```

Example:
```
101,-1,11,13,0,Should I learn C++ first or Java,I think C++ is a better Start
203,101,11,13,0,Why do you think so!,Just Google. There is an answer on Quora.
```

---

## How to Compile

Requires a standard C++17 compatible compiler:

```bash
g++ 04_AskMe.cpp -o askme_v04
```

Run:

```bash
./askme_v04
```

---

## Quick Start / Testing

1. Create `users.txt` and `questions.txt` in the same directory as the compiled executable (sample content above).
2. Run the executable.
3. Use the interactive menu to sign up, log in, and exercise features.

Tip: If the files are missing the program will start with empty data and print a friendly warning.

---

## Implementation Notes

- The code uses simple CSV parsing (fields must not contain commas). For production use, adopt a robust CSV library or use JSON.
- All data is loaded into memory during operations and saved back to disk on updates (overwrite). This is easy to reason about but not suitable for heavy concurrent use.
- Passwords are stored in plain text (educational only). For real projects use secure password hashing (e.g., bcrypt).
- Thread deletion removes whole thread when a parent question is deleted.

---

## Sample Files (for quick copy/paste)

Place the following lines in `questions.txt`:

```
101,-1,11,13,0,Should I learn C++ first or Java,I think C++ is a better Start
203,101,11,13,0,Why do you think so!,Just Google. There is an answer on Quora.
205,101,45,13,0,What about python?,
211,-1,13,11,1,It was nice to chat to you,For my pleasure Dr Mostafa
212,-1,13,45,0,Please search archive before asking,
300,101,11,13,1,Is it ok to learn Java for OOP?,Good choice
301,-1,11,13,0,Free to meet?,
302,101,11,13,1,Why so late in reply?,
```

Place the following lines in `users.txt`:

```
13,mostafa,111,mostafa_saad_ibrahim,mostafa@gmail.com,1
11,noha,222,noha_salah,nono171@gmail.com,0
45,ali,333,ali_wael,wael@gmail.com,0
```

---

## License

MIT — feel free to reuse and adapt for learning purposes. Include attribution if publishing derivatives.

---

If you'd like, I can also:
- Save the corrected `04_AskMe.cpp` into `/mnt/data` so you can download it directly, or
- Convert the project to use `std::vector` more extensively or add file-backed persistence improvements.

