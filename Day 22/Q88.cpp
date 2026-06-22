#include <iostream>
#include <string>
using namespace std;
int main() {
string str, result = "";
cout << "Enter The  string: ";
getline(cin, str);
for (int i = 0; i < str.length(); i++) {
if (str[i] != ' ') {
result += str[i];
}
}
cout << "thus  after the removal of the spaces from the string : " << result << endl;
return 0;
}
