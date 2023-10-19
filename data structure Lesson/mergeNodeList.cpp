#include <iostream>
#include <iomanip>
using namespace std;

// 定义链表结点
template <class Type>
struct ListNode
{
    Type data;
    ListNode *next;
    ListNode(Type x) : data(x), next(NULL) {}
};

// 定义链表类
template <class Type>
class LinkedList
{
private:
    ListNode<Type> *head; // 头结点
public:
    LinkedList()
    {
        head = new ListNode<Type>(0);
    }

    // 创建链表
    void createList(int n)
    {
        ListNode<Type> *p = head;
        for (int i = 0; i < n; i++)
        {
            Type data;
            cin >> data;
            ListNode<Type> *newNode = new ListNode<Type>(data);
            p->next = newNode;
            p = p->next;
        }
    }

    // 增加新结点
    void addNode(Type data)
    {
        ListNode<Type> *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        ListNode<Type> *newNode = new ListNode<Type>(data);
        p->next = newNode;
    }

    // 插入新结点
    void insertNode(int pos, Type data)
    {
        ListNode<Type> *p = head;
        for (int i = 0; i < pos; i++)
        {
            p = p->next;
        }
        ListNode<Type> *newNode = new ListNode<Type>(data);
        newNode->next = p->next;
        p->next = newNode;
    }

    // 定位数据
    int findNode(Type data)
    {
        ListNode<Type> *p = head->next;
        int pos = 0;
        while (p != NULL)
        {
            if (p->data == data)
            {
                return pos;
            }
            pos++;
            p = p->next;
        }
        return -1;
    }

    // 删除数据
    void deleteNode(Type data)
    {
        ListNode<Type> *p = head;
        while (p->next != NULL)
        {
            if (p->next->data == data)
            {
                ListNode<Type> *temp = p->next;
                p->next = temp->next;
                delete temp;
                return;
            }
            p = p->next;
        }
    }

    // 打印链表
    void printList()
    {
        ListNode<Type> *p = head->next;
        while (p != NULL)
        {
            cout << p->data;
            if (p->next != NULL)
                cout << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 合并链表
    void mergeList(LinkedList<Type> &list1, LinkedList<Type> &list2)
    {
        ListNode<Type> *p1 = list1.head->next;
        ListNode<Type> *p2 = list2.head->next;
        ListNode<Type> *p = head;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data < p2->data)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != NULL)
        {
            p->next = p1;
        }
        if (p2 != NULL)
        {
            p->next = p2;
        }
    }
};

int main()
{
    int m;
    while (cin >> m)
    {
        for (int i = 0; i < m; i++)
        {
            int n1, n2;
            cin >> n1;
            LinkedList<int> list1;
            list1.createList(n1);
            cin >> n2;
            LinkedList<int> list2;
            list2.createList(n2);
            LinkedList<int> list3;
            list3.mergeList(list1, list2);
            list3.printList();
        }
    }
    return 0;
}