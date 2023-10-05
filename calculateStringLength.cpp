#include <iostream>
using namespace std;
int stringLength(const char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[99];
    while (cin.getline(str, 99)) {
        int length = stringLength(str);
        cout << length << endl;
    }
    return 0;
}
