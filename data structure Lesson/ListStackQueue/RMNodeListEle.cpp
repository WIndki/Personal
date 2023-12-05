#include <iostream>
using namespace std;

// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 创建链表
ListNode* createLinkedList(int n) {
    ListNode* head = new ListNode(0);  // 创建头结点
    ListNode* cur = head;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        cur->next = newNode;
        cur = cur->next;
    }
    return head;
}

// 删除链表中值为e的元素
ListNode* deleteElements(ListNode* head, int e) {
    ListNode* dummy = new ListNode(0);  // 创建虚拟头结点
    dummy->next = head;
    ListNode* cur = dummy;
    while (cur->next != nullptr) {
        if (cur->next->val == e) {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        } else {
            cur = cur->next;
        }
    }
    return dummy->next;
}

// 输出链表
void printLinkedList(ListNode* head) {
    ListNode* cur = head->next;
    while (cur != nullptr) {
        cout << cur->val<< " ";
        cur = cur->next;
    }
}

int main() {
    int n;
    cin >> n;
    ListNode* head = createLinkedList(n);
    int e;
    cin >> e;
    ListNode* newHead = deleteElements(head, e);
    printLinkedList(newHead);
    return 0;
}
