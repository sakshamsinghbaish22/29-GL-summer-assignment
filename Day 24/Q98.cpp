#include <iostream>
#include <string>
#include <unordered_set>
int main() {
std::string input;
if (!std::getline(std::cin, input)) {
return 0;
}
std::unordered_set<char> seen;
std::string output;
output.reserve(input.size());
for (char c : input) {
if (seen.find(c) == seen.end()) {
seen.insert(c);
output.push_back(c);
}
}
std::cout << output;
return 0;
}
