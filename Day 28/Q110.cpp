#include <iostream>
#include <vector>
#include <string>
#include <limits>

class BankAccount {
private:
    int accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(int accNo, const std::string &name, double initialBalance)
        : accountNumber(accNo), accountHolder(name), balance(initialBalance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. New balance: " << balance << "\n";
        } else {
            std::cout << "Invalid deposit amount." << "\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount." << "\n";
        } else if (amount > balance) {
            std::cout << "Insufficient balance." << "\n";
        } else {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << "\n";
        }
    }

    void display() const {
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Account Holder: " << accountHolder << "\n";
        std::cout << "Balance: " << balance << "\n";
    }
};

BankAccount *findAccount(std::vector<BankAccount> &accounts, int accountNumber) {
    for (auto &account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

int main() {
    std::vector<BankAccount> accounts;
    int choice = 0;

    while (true) {
        std::cout << "\nBank Account System\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Display Account\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int accNo;
            std::string name;
            double initialBalance;

            std::cout << "Enter account number: ";
            std::cin >> accNo;
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            std::cout << "Enter account holder name: ";
            std::getline(std::cin, name);
            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;

            if (findAccount(accounts, accNo) == nullptr) {
                accounts.emplace_back(accNo, name, initialBalance);
                std::cout << "Account created successfully." << "\n";
            } else {
                std::cout << "Account number already exists." << "\n";
            }
        } else if (choice == 2) {
            int accNo;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accNo;
            BankAccount *account = findAccount(accounts, accNo);
            if (account) {
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                account->deposit(amount);
            } else {
                std::cout << "Account not found." << "\n";
            }
        } else if (choice == 3) {
            int accNo;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accNo;
            BankAccount *account = findAccount(accounts, accNo);
            if (account) {
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account->withdraw(amount);
            } else {
                std::cout << "Account not found." << "\n";
            }
        } else if (choice == 4) {
            int accNo;
            std::cout << "Enter account number: ";
            std::cin >> accNo;
            BankAccount *account = findAccount(accounts, accNo);
            if (account) {
                account->display();
            } else {
                std::cout << "Account not found." << "\n";
            }
        } else if (choice == 5) {
            std::cout << "Exiting system." << "\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << "\n";
        }
    }

    return 0;
}
