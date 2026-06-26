#include <iostream>
#include <limits>

int main() {
    double a, b;
    int choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Divide\n";
        std::cout << "5. Modulus (integers)\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }

        if (choice == 6) {
            break;
        }

        if (choice < 1 || choice > 6) {
            std::cout << "Invalid choice. Please select a valid option.\n\n";
            continue;
        }

        if (choice == 5) {
            long long x, y;
            std::cout << "Enter two integers: ";
            if (!(std::cin >> x >> y)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter integer values.\n\n";
                continue;
            }
            if (y == 0) {
                std::cout << "Division by zero is not allowed.\n\n";
                continue;
            }
            std::cout << "Result: " << (x % y) << "\n\n";
        } else {
            std::cout << "Enter two numbers: ";
            if (!(std::cin >> a >> b)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter numeric values.\n\n";
                continue;
            }

            switch (choice) {
                case 1:
                    std::cout << "Result: " << (a + b) << "\n\n";
                    break;
                case 2:
                    std::cout << "Result: " << (a - b) << "\n\n";
                    break;
                case 3:
                    std::cout << "Result: " << (a * b) << "\n\n";
                    break;
                case 4:
                    if (b == 0) {
                        std::cout << "Division by zero is not allowed.\n\n";
                    } else {
                        std::cout << "Result: " << (a / b) << "\n\n";
                    }
                    break;
            }
        }
    } while (true);

    std::cout << "Calculator exited.\n";
    return 0;
}
