#include "cs25_a27.h"

int main() {
    Bookstore store;

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 10.99);
    Book book2("1984", "George Orwell", "9780451524935", 8.99);
    Book book3("To Kill a Mockingbird", "Harper Lee", "9780061120084", 7.99);
    Book book4("The Catcher in the Rye", "J.D. Salinger", "9780316769488", 6.99);
    
    store.addBook(book1);
    store.addBook(book2);
    store.addBook(book3);
    store.addBook(book4);

    // Display all books
    cout << "\nBooks in the bookstore:\n";
    store.displayAllBooks();

    // Find a book by ISBN
    string searchIsbn = "9780451524935";
    Book* foundBook = store.findBookByIsbn(searchIsbn);
    if (foundBook != nullptr) {
        cout << "\nFound book with ISBN " << searchIsbn << ":\n";
        foundBook->displayBook();
    }
    else {
        cout << "\nBook with ISBN " << searchIsbn << " not found.\n";
    }

    // Find books by Title
    string searchTitle = "1984";
    vector<Book> booksByTitle = store.findBookByTitle(searchTitle);
    if (!booksByTitle.empty()) {
        cout << "\nBooks found with title '" << searchTitle << "':\n";
        for (const auto& book : booksByTitle) {
            book.displayBook();
        }
    }
    else {
        cout << "\nNo books found with title '" << searchTitle << "'.\n";
    }

    // Using the global operator<< function to display book details
    cout << "\nUsing the global operator<< function:\n";
    cout << book1 << endl;

    return 0;
}
