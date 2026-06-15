 #include <iostream>
using namespace std;
int main() {
int arr[5];
cout << "Enter 5 elements of the array : ";
for (int i = 0; i < 5; i++) {
cin >> arr[i];
}
int index = 0;
for (int i = 0; i < 5; i++) {
if (arr[i] != 0) {
arr[index] = arr[i];
index++;
}
}
while (index < 5) {
arr[index] = 0;
index++;
}
cout << "array after reversing zeros to the end : ";
for (int i = 0; i < 5; i++) {
cout << arr[i] << " ";
}
return 0;
}