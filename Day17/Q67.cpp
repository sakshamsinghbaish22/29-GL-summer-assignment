#include <iostream>
#include <set>
using namespace std;
int main() {
int n1, n2;
cout << "Enter size of first array: ";
cin >> n1;
int arr1[n1];
cout << "Enter elements of first array: ";
for (int i = 0; i < n1; i++) {
cin >> arr1[i];
}
cout << "Enter size of second array: ";
cin >> n2;
int arr2[n2];
cout << "Enter elements of second array: ";
for (int i = 0; i < n2; i++) {
cin >> arr2[i];
}
set<int> s1, intersectionSet;
for (int i = 0; i < n1; i++) {
s1.insert(arr1[i]);
}
for (int i = 0; i < n2; i++) {
if (s1.find(arr2[i]) != s1.end()) {
intersectionSet.insert(arr2[i]);
}
}
cout << "Intersection of arrays: ";
for (int x : intersectionSet) {
cout << x << " ";
}
return 0;
}