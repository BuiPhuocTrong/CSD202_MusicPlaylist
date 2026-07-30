# 🎵 Music Playlist Management using Singly Linked List

A C++ console application for managing a music playlist using a **Singly Linked List**. This project was developed as Assignment 1 for the **CSD202 - Data Structures and Algorithms** course.

---

## 📌 Assignment Objective

The purpose of this project is to practice implementing a **Singly Linked List** from scratch and applying it to a real-world problem: music playlist management.

The assignment focuses on:

- Dynamic memory allocation
- Pointer manipulation
- Object-Oriented Programming (OOP)
- Modular program design
- Linked List operations

---

## 📖 Problem Description

Each song in the playlist contains the following information:

| Attribute | Data Type |
|-----------|-----------|
| Song ID | string |
| Title | string |
| Artist | string |
| Duration | int (seconds) |

The playlist is implemented as a **Singly Linked List**, where each node stores a song and a pointer to the next node.

---

## ✨ Features

### 1. Add Song

- Add to the beginning of the playlist
- Add to the end of the playlist
- Add at a specified position

---

### 2. Delete Song

- Delete by Song ID
- Delete the first song
- Delete the last song
- Delete at a specified position

---

### 3. Search Song

- Search by Song ID
- Search songs whose title contains a given keyword

---

### 4. Sort Playlist

Sort songs by:

- Duration (Ascending)
- Duration (Descending)
- Title (A → Z)
- Title (Z → A)

---

### 5. Update Song

Update the information of an existing song:

- Title
- Artist
- Duration

using the Song ID.

---

### 6. Display Playlist

Display all songs currently stored in the playlist.

---

## 🧩 Data Structure

The playlist is implemented using a **Singly Linked List**.

```
Head
 │
 ▼
+---------+      +---------+      +---------+
| Song 1  | ---> | Song 2  | ---> | Song 3  | ---> NULL
+---------+      +---------+      +---------+
```

Each node contains:

```cpp
Song data
Node* next;
```

No STL linked list containers (such as `std::list`) are used.

---

## 🛠 Technologies

- C++
- Object-Oriented Programming
- Dynamic Memory Allocation
- Singly Linked List
- Pointer Manipulation

---

## 📂 Project Structure

```
Project
│
├── header/
│   ├── Song.h
│   ├── Node.h
│   ├── Playlist.h
│   ├── Validation.h
│   └── ConsoleInput.h
│
├── src/
│   ├── main.cpp
│   ├── Playlist.cpp
│   ├── Validation.cpp
│   ├── ConsoleInput.cpp
│   └── ...
│
├── output/
│
├── build.bat
│
└── README.md
```

> The actual file names may vary depending on your implementation.

---

## 🚀 Build

Compile all source files:

```bash
g++ -Iheader src/*.cpp -o output/main.exe
```

or simply run

```bash
build.bat
```

---

## ▶️ Running

After compilation:

```bash
output/main.exe
```

---

## 📋 Main Menu

```
==============================
MUSIC PLAYLIST MANAGEMENT
1. Add song
2. Delete song
3. Search song
4. Sort playlist
5. Update song information
6. Display playlist
0. Exit
==============================
```

---

## 📚 Concepts Practiced

- Singly Linked List
- Dynamic Memory Management
- Pointer Operations
- Traversal
- Insertion
- Deletion
- Searching
- Sorting
- Object-Oriented Programming
- Modular Programming

---

## 📖 Assignment Requirements

This project follows the assignment requirements:

- ✅ Use Singly Linked List
- ✅ Use classes
- ✅ Use pointers
- ✅ Implement each function separately
- ✅ Do not use STL linked list (`std::list`)

---

## 🎯 Evaluation Criteria

| Criteria | Points |
|-----------|--------|
| Correct and efficient data structure | 3 |
| Functional completeness | 3 |
| User-friendly menu | 1 |
| Code quality | 2 |
| **Total** | **10** |

---

## 👨‍💻 Author

**Student:** Bui Phuoc Trong

**Course:** CSD202 – Data Structures and Algorithms

**Assignment:** Assignment 1 – Music Playlist Management using Singly Linked List

---

## 📄 License

This repository was created for educational purposes only.
