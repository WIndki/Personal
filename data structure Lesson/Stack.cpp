#include <iostream>
#include <iomanip>
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

int main() {
    Stack<int> s;
    for(int i = 0; i < 100; i++){
        s.push(i);
    }
    for(int i = 0; i < 100; i++){
        // cout<<left;//左对齐
        // cout.width(3);//宽度
        // cout.fill();//填充的字符串，默认为空格。
        // cout<<s.pop();
        cout<<left<<setw(3)<<s.pop();//引入iomanip调用setw进行规格化处理。
        if((i+1) % 10==0)cout<<endl;
    }
    return 0;
}
