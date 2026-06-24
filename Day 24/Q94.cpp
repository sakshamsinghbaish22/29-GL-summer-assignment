#include <bits/stdc++.h>
using namespace std;
int main() {
string s;
if (!getline(cin, s))
return 0;
string compressed;
for (size_t i = 0; i < s.size(); ) {
char ch = s[i];
size_t count = 0;
while (i < s.size() && s[i] == ch) {
++count;
++i;
}
compressed += ch;
compressed += to_string(count);
}
cout << compressed;
return 0;
}
