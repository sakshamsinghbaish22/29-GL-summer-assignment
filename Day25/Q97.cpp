#include <iostream>
#include <vector>
using namespace std;
int main() {
int n, m;
if (!(cin >> n >> m)) {
return 0;
}
vector<int> a(n), b(m);
for (int i = 0; i < n; ++i) {
cin >> a[i];
}
for (int j = 0; j < m; ++j) {
cin >> b[j];
}
vector<int> merged;
merged.reserve(n + m);
int i = 0, j = 0;
while (i < n && j < m) {
if (a[i] <= b[j]) {
merged.push_back(a[i++]);
} else {
merged.push_back(b[j++]);
}
}
while (i < n) {
merged.push_back(a[i++]);
}
while (j < m) {
merged.push_back(b[j++]);
}
for (size_t k = 0; k < merged.size(); ++k) {
cout << merged[k];
if (k + 1 < merged.size()) cout << " ";
}
cout << '\n';
return 0;
}
