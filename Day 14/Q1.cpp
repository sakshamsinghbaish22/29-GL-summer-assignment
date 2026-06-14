#include <iostream>
using namespace std;

int main() {
    int arr[100], n, key;
    bool found = false;

    cout << "enter the number of the element : ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element not found";
    }

    return 0;
}