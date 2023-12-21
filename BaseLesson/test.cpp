#include <stdio.h>
#include <stdlib.h>//里面包含了malloc函数

struct LinkList//创建结构体
{
    int data;//数据域，用来保存数据。
    struct LinkList *next;//指针域，用来连接其他结点。
};

int main(void) {
    struct LinkList *head = (struct LinkList *) malloc(
            sizeof(struct LinkList));//创建头结点，并分配内存，需要的内存大小就是结构体的大小。别忘了在malloc前进行强制类型转换。（struct LinkList*）
    head->next = NULL;//头结点指针初始化
    struct LinkList *p;
    int n;//保存链表长度，即结点的个数。
    printf("请输入链表长度：\n");
    scanf("%d", &n);
    printf("输入数据：\n");
    for (int i = 0; i < n; i++)//循环创建结点
    {
        struct LinkList *s = (struct LinkList *) malloc(sizeof(struct LinkList));//创建s结点，并分配内存
        scanf("%d", &s->data);//给s结点赋值。
        //头插法建立链表
        s->next = head->next; //将链表除链表头的所有节点连接在新建节点之后
        head->next = s;//在让头结点指向新节点 注意：和上一语句顺序不能颠倒
    }//至此，链表的创建已经完成了。

    p = head;//让p指针从"头"开始。
    while (p->next != NULL)//如果p的下一个结点不为NULL，也就是说如果p结点后还有节点存在，那就输出p后面结点中保存的数据。
    {
        printf("%-5d", p->next->data);
        p = p->next;//p结点后移
    }
    printf("\n");
    return 0;
}//至此完成了链表的遍历输出。
