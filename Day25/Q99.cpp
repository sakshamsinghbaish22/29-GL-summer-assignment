#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
int n;
std::cout << "Enter number of names: ";
if (!(std::cin >> n) || n <= 0) {
std::cerr << "Invalid number of names\n";
return 1;
}
std::vector<std::string> names;
names.reserve(n);
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::cout << "Enter " << n << " names:\n";
for (int i = 0; i < n; ++i) {
std::string name;
std::getline(std::cin, name);
if (!name.empty()) {
names.push_back(name);
}else {
--i;
}
}
std::sort(names.begin(), names.end());
std::cout << "Sorted names alphabetically:\n";
for (const auto &name : names) {
std::cout << name << '\n';
}
return 0;
}
