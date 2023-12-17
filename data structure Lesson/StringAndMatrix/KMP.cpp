#include <iostream>
#include <vector>
#include <string>

std::vector<int> getNextArray(const std::string& pattern) {
    int n = pattern.size();
    std::vector<int> next(n, 0);
    int i = 1, j = 0;
    while (i < n) {
        if (pattern[i] == pattern[j]) {
            next[i++] = ++j;
        } else if (j > 0) {
            j = next[j - 1];
        } else {
            next[i++] = 0;
        }
    }
    return next;
}

int main() {
    system("chcp 65001"); // 设置控制台编码为UTF-8
    std::string pattern;
    std::cout << "请输入字符串: ";
    std::cin >> pattern;

    std::vector<int> next = getNextArray(pattern);

    std::cout << "next数组为: ";
    for (int i : next) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
