#include <stdio.h>

int main() {
    char line[30];
    printf("输入一行30个字符文字：\n");
    fgets(line, sizeof(line), stdin);  // 使用 fgets 函数读取一行字符

    int upperCase = 0;  // 大写字母个数
    int lowerCase = 0;  // 小写字母个数
    int space = 0;      // 空格个数
    int digit = 0;      // 数字个数
    int other = 0;      // 其他字符个数

    char *p = line;  // 指向字符串的指针

    while (*p != '\0') {
        if (*p >= 'A' && *p <= 'Z') {
            upperCase++;
        } else if (*p >= 'a' && *p <= 'z') {
            lowerCase++;
        } else if (*p == ' ') {
            space++;
        } else if (*p >= '0' && *p <= '9') {
            digit++;
        } else {
            other++;
        }
        p++;
    }

    printf("大写字母个数：%d\n", upperCase);
    printf("小写字母个数：%d\n", lowerCase);
    printf("空格个数：%d\n", space);
    printf("数字个数：%d\n", digit);
    printf("其他字符个数：%d\n", other);

    return 0;
}