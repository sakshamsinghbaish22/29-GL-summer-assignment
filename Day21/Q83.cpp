#include <iostream>
#include <string>
using namespace std;
int main() {
string str;
int vowels = 0, consonants = 0;
cout << "Enter a string: ";
getline(cin, str);
for (char ch : str) {
if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
vowels++;
} else {
consonants++;
}
}
}
cout << "Number of vowels = " << vowels << endl;
cout << "Number of consonants = " << consonants << endl;
return 0;
}