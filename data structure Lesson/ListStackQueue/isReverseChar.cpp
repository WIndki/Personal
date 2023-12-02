#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 50; // 栈的最大容量
const int INCREMENT = 10; // 栈的空间不足时，每次增加的容量

template <typename T>
class Stack {
private:
    int top; // 栈顶指针
    T *data = new T[MAX_SIZE]; // 栈的数据存储区
    int Length = MAX_SIZE; // 栈的长度
public:
    Stack() { top = -1; } // 构造函数，初始化栈顶指针为-1
    bool isEmpty() { return top == -1; } // 判断栈是否为空
    bool isFull() { return top == Length - 1; } // 判断栈是否已满
    void push(T x) { // 元素x入栈
        if (isFull()) {
            T* data_ = new T[Length + INCREMENT];
            for(int i = 0; i < Length; i++){
                data_[i] = data[i];
            }
            Length += INCREMENT;
            delete[] data;
            data = data_;
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

bool isReverse(string s1, string s2) {
    Stack<char> st;
    for (char c : s1) {
        st.push(c);//压栈
    }
    for (char c : s2) {
        if (st.isEmpty() || st.peek() != c) {
            return false;//首字符不符合，直接返回
        }
        st.pop();//出栈
    }
    return st.isEmpty();//返回栈是否为空
}

int main() {
    string s;
    while (getline(cin, s)) {
        int pos = s.find('&');
        string s1 = s.substr(0, pos);
        string s2 = s.substr(pos + 1);
        if (isReverse(s1, s2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
