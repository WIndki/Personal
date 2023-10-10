#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node *createList(int n) {
    Node *head = new Node(-1); // 创建头结点
    Node *cur = head; // cur指向当前结点
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node *node = new Node(data); // 创建新结点
        cur->next = node; // 将新结点插入到链表中
        cur = cur->next; // cur指向下一个结点
    }
    return head->next; // 返回链表的第一个结点
}

void printList(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        cout << cur->data;
        cur = cur->next;
        if (cur != NULL) {
            cout << " ";
        }
    }
}

Node *deleteDataInList(Node *head, int e) {
    Node *dummy = new Node(-1); // 创建虚拟头结点
    dummy->next = head; // 将虚拟头结点插入到链表中
    Node *pre = dummy; // pre指向当前结点的前一个结点
    Node *cur = head; // cur指向当前结点
    while (cur != NULL) {
        if (cur->data == e) { // 如果当前结点的值等于e
            pre->next = cur->next; // 将当前结点从链表中删除
            delete cur; // 释放当前结点的内存
            cur = pre->next; // cur指向下一个结点
        } else {
            pre = cur; // pre指向当前结点
            cur = cur->next; // cur指向下一个结点
        }
    }
    return dummy->next; // 返回链表的第一个结点
}

int main() {
    int n;
    cin >> n;
    Node *head = createList(n); // 创建链表
    int e;
    cin >> e;
    head = deleteDataInList(head, e); // 删除链表中值为e的结点
    printList(head); // 输出链表
    return 0;
}
