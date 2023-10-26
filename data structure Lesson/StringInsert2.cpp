#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 100; // 定义最大长度

class FixedString {
private:
    char str[MAX_LEN + 1]; // 字符串数组
public:
    FixedString() { // 构造函数
        memset(str, 0, sizeof(str)); // 初始化数组
    }
    FixedString(const char* s) { // 带参构造函数
        memset(str, 0, sizeof(str)); // 初始化数组
        strncpy(str, s, MAX_LEN); // 复制字符串
    }
    void print() { // 输出字符串
        cout << str;
    }
    void insert(int pos, const char* s) { // 插入字符串
        int len = strlen(s);
        if (len == 0) return;
        if (pos < 0) pos = 0;
        if (pos > strlen(str)) pos = strlen(str);
        if (strlen(str) + len > MAX_LEN) len = MAX_LEN - strlen(str);
        for (int i = strlen(str) + len; i >= pos + len; i--) {
            str[i] = str[i - len];
        }
        strncpy(str + pos, s, len);
    }
    
};

int main() {
    char input1[MAX_LEN + 1]; // 定义输入缓冲区
    cin.getline(input1, MAX_LEN + 1); // 读入字符串
    FixedString s1(input1); // 创建带参串
    char input2[MAX_LEN + 1]; // 定义输入缓冲区
    cin.getline(input2, MAX_LEN + 1); // 读入字符串
    int pos;
    cin >> pos;
    s1.insert(pos-1, input2); // 插入串
    s1.print(); // 输出带参串
    return 0;
}
