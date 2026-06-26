#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    cout << "Enter initial number of elements: ";
    cin >> size;
    if (size < 0) size = 0;
    if (size > MAX_SIZE) size = MAX_SIZE;

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Display array\n";
        cout << "2. Insert element\n";
        cout << "3. Delete element\n";
        cout << "4. Search element\n";
        cout << "5. Sort array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (size == 0) {
                    cout << "Array is empty.\n";
                } else {
                    cout << "Array elements: ";
                    for (int i = 0; i < size; ++i) {
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                }
                break;
            }
            case 2: {
                if (size >= MAX_SIZE) {
                    cout << "Array is full. Cannot insert more elements.\n";
                    break;
                }
                int value, pos;
                cout << "Enter element to insert: ";
                cin >> value;
                cout << "Enter position (0 to " << size << "): ";
                cin >> pos;
                if (pos < 0 || pos > size) {
                    cout << "Invalid position.\n";
                } else {
                    for (int i = size; i > pos; --i) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    ++size;
                    cout << "Element inserted.\n";
                }
                break;
            }
            case 3: {
                if (size == 0) {
                    cout << "Array is empty. Nothing to delete.\n";
                    break;
                }
                int pos;
                cout << "Enter position to delete (0 to " << size - 1 << "): ";
                cin >> pos;
                if (pos < 0 || pos >= size) {
                    cout << "Invalid position.\n";
                } else {
                    for (int i = pos; i < size - 1; ++i) {
                        arr[i] = arr[i + 1];
                    }
                    --size;
                    cout << "Element deleted.\n";
                }
                break;
            }
            case 4: {
                if (size == 0) {
                    cout << "Array is empty.\n";
                    break;
                }
                int key;
                cout << "Enter element to search: ";
                cin >> key;
                int index = -1;
                for (int i = 0; i < size; ++i) {
                    if (arr[i] == key) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    cout << "Element not found.\n";
                } else {
                    cout << "Element found at position " << index << ".\n";
                }
                break;
            }
            case 5: {
                for (int i = 0; i < size - 1; ++i) {
                    for (int j = i + 1; j < size; ++j) {
                        if (arr[j] < arr[i]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                cout << "Array sorted in ascending order.\n";
                break;
            }
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
