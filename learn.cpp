#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        int sum = 0;
        int num = 0;
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
            } else {
                sum += num;
                num = 0;
            }
        }
        sum += num;
        cout << sum << endl;
    }
    return 0;
}
