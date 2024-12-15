# Library-Management-System

Designed and implemented a Library Management System in C++ using OOP principles. 
The project includes features like adding, issuing, and returning books with persistent data storage using file handling.
Demonstrated mastery of encapsulation, inheritance, polymorphism, and dynamic memory management.

## Key OOP Concepts in Code

### Encapsulation:
- The `Book` class uses private attributes like `title`, `author`, `bookID`, and `isIssued`.
- Methods like `issueBook` and `returnBook` provide controlled access to these attributes.

### Inheritance:
- The `Member` class inherits from the `Person` class and overrides the `display` method.

### Polymorphism:
- `display` is a virtual function in the base class and overridden in the derived class.

### Dynamic Behavior:
- Menu-driven functionality demonstrates dynamic program behavior.

## How to Test the Code

1. Compile the program using a C++ compiler:
   ```bash
   g++ library_management.cpp -o library_management
   ```

2. Run the executable:
   ```bash
   ./library_management
   ```

3. Follow the menu options to display, issue, and return books.
