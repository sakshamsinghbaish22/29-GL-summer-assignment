#include <iostream>
using namespace std;
int main() {
int arr[5];
cout << "Enter 5 elements: ";
for (int i = 0; i < 5; i++) {
cin >> arr[i];
}
int last = arr[4];
for (int i = 4; i > 0; i--) {
arr[i] = arr[i - 1];
}
arr[0] = last;
cout << "Array after right rotation: ";
for (int i = 0; i < 5; i++) {
cout << arr[i] << " ";
}
return 0;
}