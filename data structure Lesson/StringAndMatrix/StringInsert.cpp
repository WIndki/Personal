#include <iostream>

using namespace std;

size_t mystrlen(const char* str) {
    size_t len = 0;
    while (*str++) {
        ++len;
    }
    return len;
}

char* mystrcpy(char* dest, const char* src) {
    char* ret = dest;
    while ((*dest++ = *src++) != '\0');
    return ret;
}

void insert(char* s, char* t, int pos) {
    int len_s = mystrlen(s);
    int len_t = mystrlen(t);
    char result[len_s + len_t + 1];
    int i;
    for (i = 0; i < pos; i++) {
        result[i] = s[i];
    }
    for (int j = 0; j < len_t; j++) {
        result[i + j] = t[j];
    }
    for (int j = pos; j < len_s; j++) {
        result[i + len_t + j - pos] = s[j];
    }
    result[len_s + len_t] = '\0';
    mystrcpy(s, result);
}

int main() {
    char s[20], t[20];
    int pos;
    cin.getline(s, 100);
    cin.getline(t, 100);
    cin >> pos;
    insert(s, t, pos-1);
    cout << s;
    return 0;
}
