#include <iostream>
using namespace std;
/*
链表类
函数列表：
LinkedList() 构造函数，默认前后相连
~LinkedList() 析构函数
void clear() 清空链表
bool isEmpty() 判断链表是否为空
int getLength() 获取链表长度
T get(int index) 获取指定位置的元素
int locate(T value) 查找元素，返回下标
void insert(int index, T value) 在指定位置插入元素
void changeV(T value,int pos) 修改指定位置的元素
void push_back(T value) 在末尾添加元素
void push_front(T value) 在开头添加元素
T prev(int index) 获取前驱元素
T next(int index) 获取后继元素
void remove(int index) 删除指定位置的元素
void print() 打印链表
*/
template <class T>
struct Node {//按双向链表结构体定义，可单向使用
    T data;
    Node* next;
    Node* prev;
    Node() {
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;
    public:
        LinkedList() {//构造函数，默认前后相连
            head = new Node<T>;
            tail = new Node<T>;
            head->next = tail;
            tail->prev = head;//双向链表
            length = 0;//头结点不计入长度
        }
        ~LinkedList() {//析构函数
            clear();
            delete head;
            delete tail;
        }
        void clear() {//清空链表
            Node<T>* p = head->next;
            while (p != tail) {
                Node<T>* q = p->next;
                delete p;
                p = q;
            }
            head->next = tail;
            tail->prev = head;
            length = 0;
        }
        bool isEmpty() {//判断链表是否为空
            return length == 0;
        }
        int getLength() {//获取链表长度
            return length;
        }
        T get(int index) {//获取指定位置的元素
            if (index < 0 || index >= length) {
                cout << "index out of range" << endl;
                return -1;
            }
            Node<T>* p = head->next;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            return p->data;
        }
        int locate(T value) {//查找元素，返回下标
            Node<T>* p = head->next;
            int index = 0;
            while (p != tail) {
                if (p->data == value) {
                    return index;
                }
                p = p->next;
                index++;
            }
            return -1;
        }
        void insert(int index, T value) {//在指定位置插入元素
            if (index < 0 || index > length) {
                cout << "index out of range" << endl;
                return;
            }
            Node<T>* p = head;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            Node<T>* q = new Node<T>;
            q->data = value;
            q->next = p->next;
            q->prev = p;
            p->next->prev = q;
            p->next = q;
            length++;
        }
        void changeV(T value,int pos){//修改指定位置的元素
            Node<T>* p = head->next;
            for (int i = 0; i < pos; i++) {
                p = p->next;
            }
            p->data = value;
        }
        void push_back(T value) {//在末尾添加元素
            insert(length, value);
        }
        void push_front(T value) {//在开头添加元素
            insert(0, value);
        }
        T prev(int index) {//获取前驱元素
            if (index < 0 || index >= length) {
                cout << "index out of range" << endl;
                return -1;
            }
            Node<T>* p = head->next;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            return p->prev->data;
        }
        T nextv(int index) {//获取后继元素
            if (index < 0 || index >= length) {
                cout << "index out of range" << endl;
                return -1;
            }
            Node<T>* p = head->next;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            return p->next->data;
        }
        void remove(int index) {//删除指定位置的元素
            if (index < 0 || index >= length) {
                cout << "index out of range" << endl;
                return;
            }
            Node<T>* p = head->next;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            length--;
        }
        T pop_back(){
            T temp = get(length - 1);
            remove(length - 1);
            return temp;
        }
        T pop_front(){
            T temp = get(0);
            remove(0);
            return temp;
        }
        void print() {//打印链表
            Node<T>* p = head->next;
            while (p != tail) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
};