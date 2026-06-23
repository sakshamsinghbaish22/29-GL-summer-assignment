#include <iostream>
#include <string>
using namespace std;
int main() {
string str;
cout << "Enter the string: ";
getline(cin, str);
int freq[256] = {0};
for (char ch : str) {
freq[ch]++;
}
for (char ch : str) {
if (freq[ch] > 1) {
cout << "First repeating character is : " << ch << endl;
return 0;
}
}
cout << "No repeating character found." << endl;
return 0;
}