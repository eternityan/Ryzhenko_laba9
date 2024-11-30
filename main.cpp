#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;
    int year;

    Book(const string &title, const string &author, const string &isbn, const int year)
        : title(title), author(author), isbn(isbn), year(year) {
    }

    void print() {
        cout << "Title: " << title << ", Author: " << author
                << ", ISBN: " << isbn << ", Year: " << year << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book &book) {
        books.push_back(book);
    }

    void removeBookByISBN(const string &isbn) {
        bool found = false;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].isbn == isbn) {
                books.erase(books.begin() + i);
                found = true;
                cout << "Book with ISBN " << isbn << " removed." << endl;
                break;
            }
        }
        if (!found)
            cout << "Book with ISBN " << isbn << " not found." << endl;
    }

    void searchBooksByAuthor(char *author) {
        bool found = false;
        for (auto &book: books)
            if (book.author == author) {
                book.print();
                found = true;
            }
        if (!found)
            cout << "No books found by author: " << author << endl;
    }

    void displayAllBooks() {
        if (books.empty())
            cout << "No books in the library." << endl;
        else
            for (auto &book: books)
                book.print();
    }

    void searchBooksByYearRange(int startYear, int endYear) {
        bool found = false;
        for (auto &book: books)
            if (book.year >= startYear && book.year <= endYear) {
                book.print();
                found = true;
            }
        if (!found)
            cout << "No books found in the year range " << startYear << " - " << endYear << endl;
    }
};

int main() {
    Library library;
    library.addBook(Book("C++ Programming", "Bjarne Stroustrup", "978-0321563842", 2011));
    library.addBook(Book("Effective C++", "Scott Meyers", "978-0321334879", 2005));
    library.addBook(Book("Clean Code", "Robert C. Martin", "978-0132350884", 2008));
    cout << "All books in library: " << endl;
    library.displayAllBooks();
    cout << endl << "Searching books by author 'Bjarne Stroustrup': " << endl;
    library.searchBooksByAuthor("Bjarne Stroustrup");
    cout << endl << "Removing book with ISBN '978-0321334879': " << endl;
    library.removeBookByISBN("978-0321334879");
    cout << endl << "All books after removal: " << endl;
    library.displayAllBooks();
    cout << endl << "Searching books published between 2000 and 2010: " << endl;
    library.searchBooksByYearRange(2000, 2010);
    return 0;
}
