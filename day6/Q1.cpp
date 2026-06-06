#include <iostream>
#include <string>
#include <algorithm>

std::string decimalToBinary(int n) {
    if (n == 0) return "0";
    
    std::string binary = "";
    while (n > 0) {
        binary += std::to_string(n % 2); 
        n /= 2;                          
    }
    std::reverse(binary.begin(), binary.end());
    return binary;
}

int main() {
    int decimalNum =25;
    std::cout << "Binary: " << decimalToBinary(decimalNum) << std::endl;
    
    return 0;
}
