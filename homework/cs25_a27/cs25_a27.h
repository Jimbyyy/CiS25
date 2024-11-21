// Bookstore.h
#ifndef CS25_A27_H
#define CS25_A27_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    double price;

public:
    // Constructor to initialize a book
    Book(string title, string author, string isbn, double price);
    Book() = default;

    // Getter functions for the book details
    string getTitle() const;
    string getAuthor() const;
    string getIsbn() const;
    double getPrice() const;

    // Function to display book details
    void displayBook() const;

    bool operator==(const Book& other) const;
};

class Bookstore {
private:
    vector<Book> books;

public:
    // Function to add a book to the bookstore inventory
    void addBook(const Book& book);

    // Function to find a book by ISBN
    Book* findBookByIsbn(const string& isbn);

    // Function to find a book by Title
    vector<Book> findBookByTitle(const string& title);

    // Function to display all books in the bookstore
    void displayAllBooks() const;
};

// Global operator overloading for << to display book details
ostream& operator<<(ostream& out, const Book& book);

#endif
