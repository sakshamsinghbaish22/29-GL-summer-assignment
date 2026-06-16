#include <iostream>
using namespace std;
int main() {
int n;
cout << "Enter value of n: ";
cin >> n;
int arr[n - 1];
int sum = 0;
cout << "Enter the  " << n - 1 << " elements are : ";
for (int i = 0; i < n - 1; i++) {
cin >> arr[i];
sum += arr[i];
}
int expectedSum = n * (n + 1) / 2;
int missingNumber = expectedSum - sum;
cout << " the missing number  is = " << missingNumber;
return 0;
}