#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Book {
    int id;
    std::string title;
    std::string author;
    bool available;
};

void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addBook(std::vector<Book>& library) {
    Book book;
    std::cout << "Enter book ID: ";
    std::cin >> book.id;
    clearInput();
    std::cout << "Enter book title: ";
    std::getline(std::cin, book.title);
    std::cout << "Enter book author: ";
    std::getline(std::cin, book.author);
    book.available = true;
    library.push_back(book);
    std::cout << "Book added successfully.\n";
}

void displayBooks(const std::vector<Book>& library) {
    if (library.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    std::cout << "\nLibrary Books:\n";
    for (const auto& book : library) {
        std::cout << "ID: " << book.id
                  << " | Title: " << book.title
                  << " | Author: " << book.author
                  << " | " << (book.available ? "Available" : "Issued")
                  << "\n";
    }
}

Book* findBook(std::vector<Book>& library, int id) {
    for (auto& book : library) {
        if (book.id == id) {
            return &book;
        }
    }
    return nullptr;
}

void searchBook(const std::vector<Book>& library) {
    if (library.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    int id;
    std::cout << "Enter book ID to search: ";
    std::cin >> id;
    for (const auto& book : library) {
        if (book.id == id) {
            std::cout << "Book found:\n";
            std::cout << "ID: " << book.id
                      << " | Title: " << book.title
                      << " | Author: " << book.author
                      << " | " << (book.available ? "Available" : "Issued")
                      << "\n";
            return;
        }
    }
    std::cout << "Book with ID " << id << " not found.\n";
}

void issueBook(std::vector<Book>& library) {
    if (library.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    int id;
    std::cout << "Enter book ID to issue: ";
    std::cin >> id;
    Book* book = findBook(library, id);
    if (book == nullptr) {
        std::cout << "Book with ID " << id << " not found.\n";
    } else if (!book->available) {
        std::cout << "Book is already issued.\n";
    } else {
        book->available = false;
        std::cout << "Book issued successfully.\n";
    }
}

void returnBook(std::vector<Book>& library) {
    if (library.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    int id;
    std::cout << "Enter book ID to return: ";
    std::cin >> id;
    Book* book = findBook(library, id);
    if (book == nullptr) {
        std::cout << "Book with ID " << id << " not found.\n";
    } else if (book->available) {
        std::cout << "Book is already available in the library.\n";
    } else {
        book->available = true;
        std::cout << "Book returned successfully.\n";
    }
}

int main() {
    std::vector<Book> library;
    int choice;

    do {
        std::cout << "\nMini Library System\n";
        std::cout << "1. Add book\n";
        std::cout << "2. Display books\n";
        std::cout << "3. Search book by ID\n";
        std::cout << "4. Issue book\n";
        std::cout << "5. Return book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (
            
            
            
            
            
            
            choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                searchBook(library);
                break;
            case 4:
                issueBook(library);
                break;
            case 5:
                returnBook(library);
                break;
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 6.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
