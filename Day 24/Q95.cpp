#include <bits/stdc++.h>
using namespace std;
int main() {
string word, longest;
while (cin >> word) {
if (word.size() > longest.size()) {
longest = word;
}
}
if (!longest.empty()) {
cout << longest;
}
return 0;
}
