# Library System

A simple C++ console application for managing users and books in a library.  
Supports adding, searching, updating, deleting users and books, assigning authors, and rating books.

## Project Structure

- `main.cpp` — Main menu and program logic
- `User.h` / `User.cpp` — User class and its implementation
- `Book.h` / `Book.cpp` — Book class and its implementation
- `UserList.h` / `UserList.cpp` — User list management
- `BookList.h` / `BookList.cpp` — Book list management

## How to Build

Open a terminal in the project directory and run:

```sh
g++ main.cpp User.cpp Book.cpp UserList.cpp BookList.cpp -o library.exe
```

## How to Run

After building, run:

```sh
./library.exe
```

or on Windows:

```sh
library.exe
```

## Features

- Add, search, update, and delete users
- Add, search, update, and delete books
- Assign authors to books
- Rate books and view highest-rated book
- Display all users and books

## Requirements

- C++ compiler (e.g., g++)
- Console/terminal access

## Notes

- All data is stored in memory (no file/database persistence).
- The program uses simple console menus for interaction.

