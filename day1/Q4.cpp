#include <iostream>
using namespace std;

int main() {
    int number;
    int count = 0;
    cout << "Enter an integer: ";
    cin >> number;
    int originalNumber = number;
    if (number == 0) {
        count = 1;
       } 
    else {
        if (number < 0) {
            number = -number;
        }
        while (number > 0) {
            number = number / 10;
            count++;              
        }
    }
    cout << "The number of digits in " << originalNumber << " is: " << count << endl;

    return 0;
}