#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Duplicate elements are: ";

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate)
            continue;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;
            }
        }
    }

    return 0;
}