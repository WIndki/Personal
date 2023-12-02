#include <iostream>
using namespace std;

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

int main() {
    system("chcp 65001");
    LinkedList<int> list;
    int n;
    cout << "请输入链表长度：";
    cin >> n;
    cout << "请输入链表元素：";
    list.createList(n);
    cout << "链表创建成功，当前链表为：";
    list.printList();

    int data;
    cout << "请输入要增加的结点的值：";
    cin >> data;
    list.addNode(data);
    cout << "增加结点后，当前链表为：";
    list.printList();

    int pos;
    cout << "请输入要插入的位置和值：";
    cin >> pos >> data;
    list.insertNode(pos, data);
    cout << "插入结点后，当前链表为：";
    list.printList();

    cout << "请输入要查找的值：";
    cin >> data;
    int index = list.findNode(data);
    if (index == -1) {
        cout << "未找到该值所处的结点" << endl;
    } else {
        cout << "该值的结点在链表中的位置为：" << index << endl;
    }
    cout << "请输入要删除的值：";
    cin >> data;
    list.deleteNode(data);
    cout << "删除结点后，当前链表为：";
    list.printList();

    return 0;
}
