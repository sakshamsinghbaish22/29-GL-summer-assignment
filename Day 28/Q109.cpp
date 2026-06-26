#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

struct Book {
    int id;
    std::string title;
    std::string author;
    bool issued;
};

void printHeader() {
    std::cout << std::left << std::setw(6) << "ID"
              << std::setw(30) << "Title"
              << std::setw(25) << "Author"
              << std::setw(10) << "Status" << "\n";
    std::cout << std::string(71, '-') << "\n";
}

void displayBooks(const std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    printHeader();
    for (const auto& book : books) {
        std::cout << std::left << std::setw(6) << book.id
                  << std::setw(30) << book.title
                  << std::setw(25) << book.author
                  << std::setw(10) << (book.issued ? "Issued" : "Available")
                  << "\n";
    }
}

Book* findBook(std::vector<Book>& books, int id) {
    for (auto& book : books) {
        if (book.id == id) {
            return &book;
        }
    }
    return nullptr;
}

void addBook(std::vector<Book>& books) {
    Book book;
    std::cout << "Enter book ID: ";
    std::cin >> book.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (findBook(books, book.id)) {
        std::cout << "Book with that ID already exists." << std::endl;
        return;
    }
    std::cout << "Enter book title: ";
    std::getline(std::cin, book.title);
    std::cout << "Enter author name: ";
    std::getline(std::cin, book.author);
    book.issued = false;
    books.push_back(book);
    std::cout << "Book added successfully." << std::endl;
}

void searchBook(const std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books available to search." << std::endl;
        return;
    }
    int choice;
    std::cout << "Search by:\n";
    std::cout << "1. Book ID\n";
    std::cout << "2. Title\n";
    std::cout << "Choose option: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool found = false;
    if (choice == 1) {
        int id;
        std::cout << "Enter book ID: ";
        std::cin >> id;
        const Book* book = nullptr;
        for (const auto& item : books) {
            if (item.id == id) {
                book = &item;
                break;
            }
        }
        if (book) {
            printHeader();
            std::cout << std::left << std::setw(6) << book->id
                      << std::setw(30) << book->title
                      << std::setw(25) << book->author
                      << std::setw(10) << (book->issued ? "Issued" : "Available")
                      << "\n";
            found = true;
        }
    } else if (choice == 2) {
        std::string title;
        std::cout << "Enter book title: ";
        std::getline(std::cin, title);
        for (const auto& book : books) {
            if (book.title == title) {
                if (!found) {
                    printHeader();
                }
                std::cout << std::left << std::setw(6) << book.id
                          << std::setw(30) << book.title
                          << std::setw(25) << book.author
                          << std::setw(10) << (book.issued ? "Issued" : "Available")
                          << "\n";
                found = true;
            }
        }
    } else {
        std::cout << "Invalid option." << std::endl;
        return;
    }
    if (!found) {
        std::cout << "Book not found." << std::endl;
    }
}

void issueBook(std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books available for issuing." << std::endl;
        return;
    }
    int id;
    std::cout << "Enter book ID to issue: ";
    std::cin >> id;
    Book* book = findBook(books, id);
    if (!book) {
        std::cout << "Book not found." << std::endl;
        return;
    }
    if (book->issued) {
        std::cout << "Book is already issued." << std::endl;
    } else {
        book->issued = true;
        std::cout << "Book issued successfully." << std::endl;
    }
}

void returnBook(std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books available for returning." << std::endl;
        return;
    }
    int id;
    std::cout << "Enter book ID to return: ";
    std::cin >> id;
    Book* book = findBook(books, id);
    if (!book) {
        std::cout << "Book not found." << std::endl;
        return;
    }
    if (!book->issued) {
        std::cout << "Book is not issued." << std::endl;
    } else {
        book->issued = false;
        std::cout << "Book returned successfully." << std::endl;
    }
}

int main() {
    std::vector<Book> books;
    int choice;

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display All Books\n";
        std::cout << "3. Search Book\n";
        std::cout << "4. Issue Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                displayBooks(books);
                break;
            case 3:
                searchBook(books);
                break;
            case 4:
                issueBook(books);
                break;
            case 5:
                returnBook(books);
                break;
            case 6:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
