#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
std::vector<std::string> words;
std::string word;
while (std::cin >> word) {
words.push_back(word);
}
std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
return a.size() < b.size();
});
for (size_t i = 0; i < words.size(); ++i) {
std::cout << words[i];
if (i + 1 < words.size()) {
std::cout << ' ';
}
}
return 0;
}
