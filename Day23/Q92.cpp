#include <iostream>
#include <string>
using namespace std;
int main() {
string str;
cout << "Enter a string: ";
getline(cin, str);
int freq[256] = {0};
for (char ch : str) {
freq[ch]++;
}
char maxChar;
int maxFreq = 0;
for (char ch : str) {
if (freq[ch] > maxFreq) {
maxFreq = freq[ch];
maxChar = ch;
}
}
cout << "Maximum occurring character: " << maxChar << endl;
cout << "Frequency: " << maxFreq << endl;
return 0;
}