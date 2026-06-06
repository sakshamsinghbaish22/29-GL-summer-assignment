#include <iostream>
using namespace std;

int main() {
    int num;
    int count = 0;

    cout << "Enter a positive number : ";
    cin >> num;
    int originalNum = num; 
    while (num > 0) {
        if (num & 1) { 
            count++;
        }
        num = num >> 1; 
    }

    cout << "The number of set bits (1s) in " << originalNum << " is: " << count << endl;

    return 0;
}
