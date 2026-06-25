#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
std::string s1, s2;
if (!std::getline(std::cin, s1))
return 0;
if (!std::getline(std::cin, s2))
return 0;
std::vector<bool> seen1(256, false);
for (unsigned char c : s1) {
seen1[c] = true;
}
std::vector<bool> common(256, false);
for (unsigned char c : s2) {
if (seen1[c]) {
common[c] = true;
}
}
bool first = true;
for (int i = 0; i < 256; ++i) {
if (common[i]) {
if (!first) {
std::cout << ' ';
}
std::cout << static_cast<char>(i);
first = false;
}
}
if (!first) {
std::cout << '\n';
}
return 0;
}
