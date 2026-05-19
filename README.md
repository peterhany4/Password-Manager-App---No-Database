# 🔐 Password Manager — No Database

A console-based **C++ Password Manager** built without any external database. It demonstrates the practical application of core data structures and algorithms studied in the Design & Analysis of Algorithms course, including Binary Search Trees (BST), sorting algorithms (Merge Sort & Quick Sort), and searching algorithms (Binary Search, Linear Search, Sentinel Search).

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Algorithms & Data Structures](#algorithms--data-structures)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Team](#team)

---

## Overview

This application lets users securely manage their app credentials entirely in-memory — no SQL, no files, no external database. User authentication is powered by a **Binary Search Tree** for O(log n) lookups, and app credentials are stored in a **dynamic vector** sorted alphabetically on demand.

The system also includes a live **algorithm benchmarking** mode, where users can empirically compare Merge Sort vs. Quick Sort, and Binary Search vs. Linear Search vs. Sentinel Linear Search — with real CPU timing in milliseconds.

---

## Features

| Feature | Description |
|---|---|
| 🔑 **User Authentication** | Login / auto-register via BST |
| ➕ **Add Password** | Store credentials for any app |
| 👁️ **View Passwords** | List all saved app credentials |
| ✏️ **Edit Password** | Update password for any saved app |
| 🗑️ **Delete Password** | Remove any saved credential |
| 🔀 **Sort Apps** | Sort app list alphabetically using Quick Sort |
| 🔍 **Search App** | Binary search on sorted app list |
| ⚡ **Sort Benchmark** | Compare Merge Sort vs. Quick Sort (CPU time in ms) |
| 📊 **Search Benchmark** | Compare Binary vs. Linear vs. Sentinel Search (CPU time in ms) |
| 🎲 **Password Generator** | Generate a strong random password of custom length |

---

## Project Structure

```
Password-Manager-App---No-Database/
│
├── Password_Manager.cpp          # Main entry point — orchestrates login & menu
│
├── App/
│   ├── app.h                     # App class: stores app name, username, password
│   └── app.cpp                   # Random password generator, getters/setters
│
├── User/
│   ├── user.h                    # User class: stores credentials + app list
│   └── user.cpp                  # Sort, search, edit, delete, and benchmark logic
│
├── BSTree/
│   ├── BSTree.h                  # BST node & tree class declarations
│   └── BSTree.cpp                # BST insert, search, and credential validation
│
├── Sort_Search_algo/
│   ├── sort_search_algo.h        # Algorithm function declarations
│   └── sort_search_algo.cpp      # Merge Sort, Quick Sort, Binary Search, Linear Search, Sentinel Search
│
└── AlgoTests/
    └── algotests.cpp             # Standalone timing harness for algorithm testing
```

---

## Algorithms & Data Structures

### 🌳 Binary Search Tree — User Authentication

Users are stored in a BST keyed on the username string. This gives **O(log n)** average-case lookup for login.

- `insert(user)` — adds a new user node
- `search(user)` — checks if a username exists (for auto-register)
- `validate(user)` — verifies username **and** password match

### 🗃️ Vector — App Storage

Each user's app credentials are stored in a `std::vector<app>`, giving **O(1) amortized** insertion and natural index-based access for edit/delete.

### ⚙️ Sorting Algorithms

| Algorithm | Average Case | Worst Case | Space |
|---|---|---|---|
| **Quick Sort** | O(n log n) | O(n²) | O(log n) |
| **Merge Sort** | O(n log n) | O(n log n) | O(n) |

Both are benchmarked live over 1,000 iterations so you can see which is faster on your actual dataset.

### 🔎 Searching Algorithms

| Algorithm | Complexity | Requires Sorted? |
|---|---|---|
| **Binary Search** | O(log n) | ✅ Yes |
| **Linear Search** | O(n) | ❌ No |
| **Sentinel Linear Search** | O(n) | ❌ No |

All three are benchmarked over 10,000 iterations per run.

---

## Getting Started

### Prerequisites

- A C++ compiler supporting **C++11** or later (e.g., `g++`, `clang++`, MSVC)

### Build & Run

```bash
# Clone the repo
git clone https://github.com/peterhany4/Password-Manager-App---No-Database.git
cd Password-Manager-App---No-Database

# Compile
g++ -std=c++11 -O2 \
    Password_Manager.cpp \
    App/app.cpp \
    User/user.cpp \
    BSTree/BSTree.cpp \
    Sort_Search_algo/sort_search_algo.cpp \
    -o PasswordManager

# Run
./PasswordManager
```

> **Windows users:** A pre-built `Password_Manager.exe` is included in the repo root — just double-click or run from a terminal.

---

## Usage

On launch, you will be prompted to log in. If your username does not exist in the system, a new account is automatically created.

```
        Password Manager        

Username: john
Password: mypassword
```

After login, the main menu appears:

```
        Password Manager        

1- show Password
2- Add Password
3- Edit Password
4- Delete Password
5- Sort Apps
6- Search App
7- Which sorting algorithm is better?
8- Which searching algorithm is better?
9- Sign out
0- Exit

Choose an index:
```

### Adding a Password

Select **2**, enter the app name and your username, then choose to either generate a strong random password or type one manually.

### Benchmarking Algorithms

- **Option 7** — runs both Merge Sort and Quick Sort 1,000 times on your current app list and prints CPU time in milliseconds.
- **Option 8** — runs Binary Search, Linear Search, and Sentinel Search 10,000 times each on a target app name and prints CPU time in milliseconds.

---

## Team

> Each team consists of exactly 6 members.

| # | Name | Id |
|---|---| --- |
| 1 | Peter Hany | 42410255 |
| 2 | George Ashraf | 42410194 |
| 3 | Ahmed Magdy Hassan | 42410439 |
| 4 | Abdallah Aboghaly | 42410410 |
| 5 | Ahmed Magdy Amen | 42410462 |
| 6 | Abdo Ismail | 42410416 |

---

## Course

**Design & Analysis of Algorithms** — Spring 2026