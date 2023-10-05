#include<stdio.h>
void main()
{ int n,a[10];
  for (n=0;n<=9;n++)
    scanf("%d",&a[n]);    //从键盘依次输入10个数
  for (n=0;n<=9;n++)
    printf("%4d",a[n]);   //以一定格式将10个数打印出来
  printf("\n");
}
