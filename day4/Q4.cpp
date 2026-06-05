#include <iostream>
#include <cmath>
using namespace std;
bool isArmstrong(int num) {
    int originalNum = num;
    int temp = num;
    int digits = 0;
    int sum = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = originalNum;
    while (temp > 0) {
        int remainder = temp % 10;
        sum += round(pow(remainder, digits));
        temp /= 10;
    }
    return (sum == originalNum);
}

int main() {
    int start, end;
    cout << "Enter the lower limit of the range: ";
    cin >> start;
    cout << "Enter the upper limit of the range: ";
    cin >> end;

    cout << "\nArmstrong numbers between " << start << " and " << end << " are:\n";
        bool found = false;
    // Loop through the given range
    for (int i = start; i <= end; ++i) {
        if (isArmstrong(i)) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None found in this range.";
    }
cout << endl;
    return 0;
}
