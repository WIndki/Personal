#include <iostream>
#include <string>
using namespace std;

int calculateSumOfNumbers(const string& input) {
    int sum = 0;
    int current_number = 0;
    bool is_in_number = false;

    for (char c : input) {//从左向右遍历input
        if (isdigit(c)) {
            current_number = current_number * 10 + (c - '0');
            is_in_number = true;
        } else {
            if (is_in_number) {//数字部分结束
                sum += current_number;
                current_number = 0;
            }
            is_in_number = false;//重置
        }
    }

    if (is_in_number) {
        sum += current_number;
    }

    return sum;
}

int main() {
    string input;
    while (getline(cin, input)) {
        int result = calculateSumOfNumbers(input);
        cout << result << endl;
    }
    return 0;
}
