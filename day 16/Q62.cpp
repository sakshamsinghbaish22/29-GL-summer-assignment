#include <iostream>
using namespace std;
int main() {
 int n;
cout << "Enter size of array: ";
cin >> n;
int arr[n];
cout << "Enter elements: ";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
int maxFreq = 0;
int maxElement = arr[0];
for (int i = 0; i < n; i++) {
int freq = 1;
for (int j = i + 1; j < n; j++) {
if (arr[i] == arr[j]) {
freq++;}
}
if (freq > maxFreq) {
maxFreq = freq;
maxElement = arr[i];
}
}
cout << "Maximum Frequency Element = " << maxElement << endl;
cout << "Frequency = " << maxFreq << endl;
return 0;
}