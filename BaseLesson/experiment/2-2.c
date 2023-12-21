#include <stdio.h>  // 需要包含 stdio.h 头文件
#define N 10

int main() {  // main 函数的返回类型应为 int
    float ave, b[N], sum = 0, *p = &ave, *q = b;  // 修正指针赋值和求平均值的方式
    printf("\n please input a %d elements sequence of number:\n", N);
    for (q < N + b ; q++) {  // 修正 for 循环中的语法错误
        scanf("%f", q);  // 修正输入语句
        sum += *q;
    }
    *p = sum / N;
    printf("\n Over the average value %f:\n", *p);
    for (q = b; q < b + N; q++)  // 修正指针重新赋值的方式
        if (*q >= *p)
            printf("%f\t", *q);
    printf("\n Under the average value %f:\n", *p);
    for (q = b; q < b + N; q++)  // 修正指针重新赋值的方式
        if (*q < *p)
            printf("%f\t", *q);
    return 0;
}