#include <iostream>
#include "NodeList.h"
using namespace std;

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
