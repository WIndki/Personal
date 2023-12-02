/*
    通过模板实现链表的基本操作
*/
#ifndef NodeList_H
#define NodeList_H
#include <iostream>
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
        head = new ListNode<Type>(0); // 头结点不存储数据
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
        ListNode<Type> *p = this->head;
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
            if (p == NULL)
            {
                cout << "插入位置无效" << endl;
                return;
            }
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
            p = p->next;
            pos++;
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
                p->next = p->next->next;
                delete temp;
                return;
            }
            p = p->next;
        }
        cout << "未找到要删除的结点" << endl;
    }

    // 打印链表
    void printList()
    {
        ListNode<Type> *p = head->next;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};
#endif