#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i) : name(n), id(i) {}
    virtual void display() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

// Derived class: Member
class Member : public Person {
public:
    Member(string n, int i) : Person(n, i) {}
    void display() override {
        cout << "Member - ";
        Person::display();
    }
};

// Class: Book
class Book {
private:
    string title;
    string author;
    int bookID;
    bool isIssued;

public:
    Book(string t, string a, int id) : title(t), author(a), bookID(id), isIssued(false) {}

    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << "Book issued successfully.\n";
        } else {
            cout << "Book is already issued.\n";
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book was not issued.\n";
        }
    }

    void displayDetails() {
        cout << "Book ID: " << bookID << ", Title: " << title
             << ", Author: " << author << ", Status: " 
             << (isIssued ? "Issued" : "Available") << endl;
    }

    int getBookID() { return bookID; }
};

// Class: Library
class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) { books.push_back(book); }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        for (auto &book : books) {
            book.displayDetails();
        }
    }

    void issueBook(int bookID) {
        for (auto &book : books) {
            if (book.getBookID() == bookID) {
                book.issueBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int bookID) {
        for (auto &book : books) {
            if (book.getBookID() == bookID) {
                book.returnBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

// Main Program
int main() {
    Library library;

    // Predefined books for demonstration
    library.addBook(Book("C++ Programming", "Bjarne Stroustrup", 101));
    library.addBook(Book("Introduction to Algorithms", "Cormen", 102));
    library.addBook(Book("Clean Code", "Robert C. Martin", 103));

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Display Books\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2: {
                int bookID;
                cout << "Enter Book ID to issue: ";
                cin >> bookID;
                library.issueBook(bookID);
                break;
            }
            case 3: {
                int bookID;
                cout << "Enter Book ID to return: ";
                cin >> bookID;
                library.returnBook(bookID);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
