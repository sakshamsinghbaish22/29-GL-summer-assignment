#include <iostream>
using namespace std;
int main() {
    int num, originalNum, rem, sum = 0;
    cout << "Enter a number: ";
    cin >> num;
    originalNum = num;
    while (num > 0) {
        rem = num % 10;
        int fact = 1;
        for (int i = 1; i <= rem; i++) {
            fact = fact * i;
        }
        sum = sum + fact;
        num = num / 10;
    }
    if (sum == originalNum) {
        cout << originalNum << " is a Strong Num." << endl;
    } else {
        cout << originalNum << " is NOT a Strong Num." << endl;
    }

    return 0;
}
