#include <iostream>
#include <string>
using namespace std;
int main() {
string str;
cout << "Enter a sentence: ";
getline(cin, str);
int words = 0;
for (int i = 0; i < str.length(); i++) {
if ((i == 0 && str[i] != ' ') || 
(str[i] != ' ' && str[i - 1] == ' ')) {
words++;
}
}
cout << "Number of words = " << words;
return 0;
}