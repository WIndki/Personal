#include <iostream>
using namespace std;

struct Node {
    int data; // 存储数据
    Node *next; // 指向下一个节点的指针
};

class LinkedList {
public:
    Node *head; // 链表头指针
    LinkedList() {
        head = NULL; // 初始化头指针为空
    }
    void insert(int value) {
        Node *newNode = new Node; // 创建新节点
        newNode->data = value; // 赋值
        newNode->next = head; // 新节点指向头节点
        head = newNode; // 头指针指向新节点
    }
    void printReverse() {
        Node* current = head; // 从头节点开始遍历
        int count = 0; // 计数器
        while (current != NULL) { // 遍历链表
            count++; // 计数器加1
            current = current->next; // 指向下一个节点
        }
        cout << count <<" "<< endl; // 输出链表长度
        while (head != NULL) { // 从头节点开始遍历
            cout << head->data << " "; // 输出节点数据
            head = head->next; // 指向下一个节点
        }
        cout << endl; // 换行
    }
};

int main() {
    LinkedList list; // 创建链表对象
    int num;
    do{ // 输入数据
        cin >> num;
        list.insert(num); // 插入数据
        if(cin.get()=='\n')break;
    }while (cin);   
    list.printReverse(); // 输出链表
    return 0;
};

