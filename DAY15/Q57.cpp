#include<iostream>
using namespace std;
int main()
{
int arr[5];
cout << "Enter 5 elements: ";
for (int i = 0; i < 5; i++) {
cin >> arr[i];
}
int start = 0, end = 4;
while (start < end) {
int temp = arr[start];
arr[start] = arr[end];
arr[end] = temp;
start++;
end--;
}
cout << "Reversed array: ";
for (int i = 0; i < 5; i++) {
cout << arr[i] << " ";
}
return 0; 
}