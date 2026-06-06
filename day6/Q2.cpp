#include <iostream>
#include <string>

int binaryToDecimal(const std::string& binary) {
    int decimalValue = 0;
    int base = 1; // 2^0

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimalValue += base;
        }
        base *= 2; 
    }
    return decimalValue;
}

int main() {
    std::string binaryStr;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryStr;

    std::cout << "Decimal value: " << binaryToDecimal(binaryStr) << std::endl;
    return 0;
}
