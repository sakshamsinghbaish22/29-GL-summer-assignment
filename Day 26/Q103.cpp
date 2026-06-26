#include <iostream>
#include <iomanip>

int main() {
    double balance = 1000.00;
    const int correctPin = 1234;
    int pin;

    std::cout << "Welcome to the ATM" << std::endl;
    std::cout << "Enter PIN: ";
    if (!(std::cin >> pin)) {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }

    if (pin != correctPin) {
        std::cout << "Incorrect PIN. Access denied." << std::endl;
        return 0;
    }

    int choice = 0;
    do {
        std::cout << "\nATM Menu" << std::endl;
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Deposit" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Current balance: $" << balance << std::endl;
                break;
            case 2: {
                double amount;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    std::cout << "Please collect your cash." << std::endl;
                    std::cout << "New balance: $" << balance << std::endl;
                } else {
                    std::cout << "Insufficient funds or invalid amount." << std::endl;
                }
                break;
            }
            case 3: {
                double amount;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    std::cout << "Deposit successful." << std::endl;
                    std::cout << "New balance: $" << balance << std::endl;
                } else {
                    std::cout << "Invalid deposit amount." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Thank you for using the ATM." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
