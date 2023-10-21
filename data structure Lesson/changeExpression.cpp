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

void changeExpression(string s){
    Stack<char> st;
    for(char c : s){//仅对括号及算符进行处理
        if(c == '('){
            st.push(c);//若左括号直接压栈
        }else if(c == ')'){
            while(st.peek() != '('){//若非左括号，将栈中相对应括号中的元素全部出栈
                cout << st.pop();
            }
            st.pop();//将左括号出栈，抛弃
        }else if(c == '+' || c == '-'){
            while(!st.isEmpty() && st.peek() != '('){//判断栈顶元素是否为左括号，若不是则出栈
                cout << st.pop();
            }
            st.push(c);//符号压栈
        }else if(c == '*' || c == '/'){
            while(!st.isEmpty() && (st.peek() == '*' || st.peek() == '/')){//输出前一个优先级高的运算符
                cout << st.pop();
            }
            st.push(c);//符号压栈
        }else{
            cout << c;
        }
    }
    while(!st.isEmpty()){
        cout << st.pop();//输出剩余符号
    }
    cout<<endl;
}

int main() {
    string s;
    while (getline(cin, s)) {
        changeExpression(s);
        cout << endl;
    }
    return 0;
}