#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter age: ";
    if (!(cin >> age)) {
        cout << "Invalid input\n";
        return 1;
    }
    if (age >= 18) {
        cout << "Eligible to vote\n";
    } else if (age >= 0) {
        cout << "Not eligible to vote\n";
    } else {
        cout << "Invalid age\n";
    }
    return 0;
}
