# Project 05 - Online Book Reader

> **A console-based online library system in C++**

---

## Overview

This project implements a **menu-driven Online Book Reader** where:

- **Admins** can log in and **add books**
- **Users** can:
  - Sign up / Log in
  - View profile
  - Browse and read books
  - Resume reading from last page
  - Maintain multiple reading sessions per book

> **No file I/O** — All data in memory  
> **No parallel sessions** — Single run only

---

## Features

| Feature              | Description                                       |
| -------------------- | ------------------------------------------------- |
| **User Types**       | Admin (`rahat/111`) and Customer (`tamanna/222`)  |
| **Reading Sessions** | Resume from last page, multiple sessions per book |
| **Navigation**       | Next / Previous page                              |
| **Session History**  | List and resume past sessions                     |
| **Add Books**        | Admin can dynamically add new books               |
| **Input Validation** | Range checks, no spaces                           |

---

## Dummy Data

| Type  | Username  | Password | Name                |
| ----- | --------- | -------- | ------------------- |
| Admin | `rahat`   | `111`    | Ualiur Rahman Rahat |
| User  | `tamanna` | `222`    | Kamrunnaher Tamanna |

### Preloaded Books

1. `C++ how to program` – Rahat
2. `Intro to algo` – Morad
3. `Data Structures in C++` – Morad

---

## How to Run

```bash
g++ -std=c++17 -o OnlineBookReader 05_OnlineBookReader.cpp
./OnlineBookReader
```
