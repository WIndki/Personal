#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 栈的最大容量

template <typename T>
class Stack {
private:
    int top; // 栈顶指针
    T data[MAX_SIZE]; // 栈的数据存储区
public:
    Stack() { top = -1; } // 构造函数，初始化栈顶指针为-1
    bool isEmpty() { return top == -1; } // 判断栈是否为空
    bool isFull() { return top == MAX_SIZE - 1; } // 判断栈是否已满
    void push(T x) { // 元素x入栈
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        data[++top] = x;
    }
    T pop() { // 栈顶元素出栈
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return data[top--];
    }
    T peek() { // 返回栈顶元素
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }
};

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl; // 输出3
    cout << s.pop() << endl; // 输出2
    cout << s.peek() << endl; // 输出1
    s.push(4);
    cout << s.peek() << endl; // 输出4
    return 0;
}
