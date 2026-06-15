#include <iostream>
using namespace std;
int main() {
int arr[5];
cout << "Enter 5 elements: ";
for (int i = 0; i < 5; i++) {
cin >> arr[i];
}
int first = arr[0];
for (int i = 0; i < 4; i++) {
arr[i] = arr[i + 1];
}
arr[4] = first;
cout << "Array after left rotation: ";
for (int i = 0; i < 5; i++) {
cout << arr[i] << " ";
}
return 0;
}