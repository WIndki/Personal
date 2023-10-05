#include <iostream>
#include <string>
using namespace std;
int compareStrings(const string &str1, const string &str2) {
    int len1 = str1.length();//通过length()获取字符串长度
    int len2 = str2.length();
    int minLen = min(len1, len2);//取两个字符串长度中最小的值

    for (int i = 0; i < minLen; i++) {//逐次比较同位置字符大小
        if (str1[i] < str2[i])
            return -1;
        else if (str1[i] > str2[i])
            return 1;
    }

    if (len1 < len2) //两字符串前minLen位相同，比较字符串长度
        return -1;
    else if (len1 > len2)
        return 1;
    else
        return 0;
}

int main() {
    string str1, str2;
    while (getline(cin, str1) && getline(cin, str2)) {
        int result = compareStrings(str1, str2);
        if (result < 0)
            cout << str1 << "<" << str2 << endl;
        else if (result > 0)
            cout << str1 << ">" << str2 << endl;
        else
            cout << str1 << "==" << str2 << endl;
    }

    return 0;
}