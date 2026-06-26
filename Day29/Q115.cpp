#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s1, s2;
    int choice;

    do {
        std::cout << "\nString Operations Menu:\n";
        std::cout << "1. Input strings\n";
        std::cout << "2. Display strings\n";
        std::cout << "3. Length of string\n";
        std::cout << "4. Concatenate strings\n";
        std::cout << "5. Compare strings\n";
        std::cout << "6. Convert to uppercase\n";
        std::cout << "7. Convert to lowercase\n";
        std::cout << "8. Find substring\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                std::cout << "Enter first string: ";
                std::getline(std::cin, s1);
                std::cout << "Enter second string: ";
                std::getline(std::cin, s2);
                break;
            case 2:
                std::cout << "First string: " << s1 << "\n";
                std::cout << "Second string: " << s2 << "\n";
                break;
            case 3:
                std::cout << "Length of first string: " << s1.length() << "\n";
                std::cout << "Length of second string: " << s2.length() << "\n";
                break;
            case 4:
                std::cout << "Concatenated string: " << (s1 + s2) << "\n";
                break;
            case 5:
                if (s1 == s2) {
                    std::cout << "Strings are equal.\n";
                } else if (s1 < s2) {
                    std::cout << "First string is less than second string.\n";
                } else {
                    std::cout << "First string is greater than second string.\n";
                }
                break;
            case 6: {
                std::string temp = s1;
                std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
                std::cout << "First string uppercase: " << temp << "\n";
                temp = s2;
                std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
                std::cout << "Second string uppercase: " << temp << "\n";
                break;
            }
            case 7: {
                std::string temp = s1;
                std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                std::cout << "First string lowercase: " << temp << "\n";
                temp = s2;
                std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                std::cout << "Second string lowercase: " << temp << "\n";
                break;
            }
            case 8: {
                std::string sub;
                std::cout << "Enter substring to find: ";
                std::getline(std::cin, sub);
                size_t pos = s1.find(sub);
                if (pos != std::string::npos) {
                    std::cout << "Substring found in first string at position " << pos << ".\n";
                } else {
                    std::cout << "Substring not found in first string.\n";
                }
                pos = s2.find(sub);
                if (pos != std::string::npos) {
                    std::cout << "Substring found in second string at position " << pos << ".\n";
                } else {
                    std::cout << "Substring not found in second string.\n";
                }
                break;
            }
            case 9:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 9);

    return 0;
}
