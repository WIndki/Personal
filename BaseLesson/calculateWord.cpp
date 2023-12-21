#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int cnt[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                cnt[tolower(s[i]) - 'a']++;//将大写字母转为小写字母，求ANSI码的差值,再将其作为数组下标
            }
        }
        for (int i = 0; i < 26; i++) {
            cout.width(3);
            cout<<cnt[i];
        }
        cout<<endl;
    }
    return 0;
}
