#include <iostream>
using namespace std;
struct LinkList//创建结构体
{
    int data;//数据域，用来保存数据。
    struct LinkList *next;//指针域，用来连接其他结点。
};
LinkList *creatNewNode(int value,LinkList *p){
	    struct LinkList *s = (struct LinkList *) malloc(sizeof(struct LinkList));//创建s结点，并分配内存
        s->data=value;//给s结点赋值。
        //尾部插法建立链表
        p->next = s; //将链表除链表头的所有节点连接在新建节点之后
        s->next = NULL;//在让头结点指向新节点 注意：和上一语句顺序不能颠倒
		(p = s);//p结点后移
		return p;//返回P结点
}

LinkList* reverseList(LinkList* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    LinkList* prev = NULL; // 前一个结点
    LinkList* curr = head; // 当前结点
    LinkList* next = NULL; // 下一个结点
    while (curr != NULL) {
        next = curr->next; // 将head->next暂存到next
        curr->next = prev; // curr->next指向前一个结点
        prev = curr; // 前一个结点后移
        curr = next; // 当前结点后移,相当于curr
    }
    return prev; // 返回逆转后的链表头结点
}

void printList(LinkList* head) {
    LinkList* p = head;
    while (p->next != NULL) {
        cout << p->data << " "; // 输出当前结点的数据
        p = p->next; // 指针后移
    }
    cout << endl;
}

int main(){
    struct LinkList *head = (struct LinkList *) malloc(sizeof(struct LinkList));//创建头结点，并分配内存，需要的内存大小就是结构体的大小。别忘了在malloc前进行强制类型转换。（struct LinkList*）
    head->next = NULL;//头结点指针初始化
    struct LinkList *p;
	p = head;//让p指针从"头"开始。
    int num;
    int count = 0;//计数器
    while(cin>>num)//循环创建结点
    {
        count++;
		p = creatNewNode(num,p);
        if (cin.get() == '\n')
            break;
    }//完成链表的创建
    p = reverseList(head);//逆序next指针
    cout<<count<<" "<<endl;
    printList(p);
    return 0;
}
