#include <iostream>
using namespace std;

int main() {
    int arr[100], n, element, frequency = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to find frequency: ";
    cin >> element;

    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            frequency++;
        }
    }

    cout << "Frequency of " << element << " = " << frequency;

    return 0;
}