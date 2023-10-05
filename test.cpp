#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> expressions;

    // 使用1到9的数字生成所有可能的排列
    string digits = "123456789";
    do {
        // 将数字分成三个部分
        string part1 = digits.substr(0, 3);
        string part2 = digits.substr(3, 3);
        string part3 = digits.substr(6, 3);

        // 将字符串转换为整数
        int num1 = stoi(part1);
        int num2 = stoi(part2);
        int num3 = stoi(part3);

        // 检查是否满足等式条件
        if (num1 + num2 == num3) {
            expressions.push_back(part1 + "+" + part2 + "=" + part3);
        }
    } while (next_permutation(digits.begin(), digits.end()));

    // 按照第一个三位数排序
    sort(expressions.begin(), expressions.end());

    // 输出结果
    for (int i = 0; i < expressions.size(); i++) {
        cout << expressions[i];
        if (i % 4 == 3 || i == expressions.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}
