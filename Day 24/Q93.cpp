#include <iostream>
#include <string>
using namespace std;
bool isRotation(string s1, string s2) {
if (s1.length() != s2.length())
return false;
string temp = s1 + s1;
return temp.find(s2) != string::npos;
}
int main() {
string s1, s2;
cout << "Enter first string: ";
cin >> s1;
cout << "Enter second string: ";
cin >> s2;
if (isRotation(s1, s2))
cout << "Strings are rotations of each other.";
else
cout << "Strings are not rotations of each other.";
return 0;
}