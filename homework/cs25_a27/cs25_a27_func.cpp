#include "cs25_a27.h"

// Implementation of Book methods

// Constructor for Book class
Book::Book(string title, string author, string isbn, double price) {
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->price = price;
}

// Getter functions for Book
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getIsbn() const {
    return isbn;
}

double Book::getPrice() const {
    return price;
}

// Display book details
void Book::displayBook() const {
    cout << "Title: " << title << ", Author: " << author
        << ", ISBN: " << isbn << ", Price: $" << price << endl;
}

// Operator Overloading: Comparison based on ISBN
bool Book::operator==(const Book& other) const {
    return isbn == other.isbn;
}

// Global operator overloading for << to display book details
ostream& operator<<(ostream& out, const Book& book) {
    out << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
        << ", ISBN: " << book.getIsbn() << ", Price: $" << book.getPrice();
    return out;
}

// Implementation of Bookstore methods

// Add a book to the bookstore inventory
void Bookstore::addBook(const Book& book) {
    books.push_back(book);
}

// Find a book by ISBN
Book* Bookstore::findBookByIsbn(const string& isbn) {
    for (int i = 0; i < books.size(); ++i) {
        if (books[i].getIsbn() == isbn) {
            return &books[i];
        }
    }
    return nullptr;
}

// Find books by Title
vector<Book> Bookstore::findBookByTitle(const string& title) {
    vector<Book> result;
    for (int i = 0; i < books.size(); ++i) {
        if (books[i].getTitle() == title) {
            result.push_back(books[i]);
        }
    }
    return result;
}

// Display all books in the bookstore
void Bookstore::displayAllBooks() const {
    if (books.empty()) {
        cout << "No books available in the store.\n";
        return;
    }
    for (int i = 0; i < books.size(); ++i) {
        books[i].displayBook();
    }
}
