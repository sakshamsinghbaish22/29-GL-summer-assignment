#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int sum = 0;
    float average;

    cout << "Enter 5 elements: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    average = (float)sum / 5;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;

    return 0;
}