#include <iostream>
using namespace std;
/*
栈类
函数列表
Stack(int size=50) 构造函数，建立一个空栈，size为栈的最大元素个数
~Stack() 析构函数，删除一个栈
bool isEmpty() 判断栈是否为空，若为空则返回true，否则返回false
void push(T value) 将元素value压栈
T pop() 出栈，将栈顶元素弹出，并返回该元素的值
T getTop() 取栈顶元素，返回该元素值，但不删除元素
*/
// void changeExpression(string s);//中缀转后缀,逆波兰式
// bool isBracketMatched(string s);//判断括号是否匹配
// void LineEdit();//行编辑程序
template <class T> class Stack {
private:
  T *data;
  int top;
  int size;

public:
  Stack(int size = 50) {
    data = new T[size]{};
    top = -1;
    this->size = size;
  }
  ~Stack() { delete[] data; }
  bool isEmpty() { return top == -1; }
  void push(T value) {
    if (top == size - 1) {
      int newSize = size * 2;
      T *newData = new T[newSize]{};
      for (int i = 0; i < size; i++) {
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
      size = newSize;
    }
    data[++top] = value;
  }
  T pop() {
    if (isEmpty()) {
      cout << "stack empty" << endl;
      return 0;
    }
    return data[top--];
  }
  T getTop() {
    if (isEmpty()) {
      cout << "stack empty" << endl;
      return 0;
    }
    return data[top];
  }
};

void changeExpression(string s) { // 中缀转后缀,逆波兰式
  Stack<char> st;
  for (char c : s) { // 仅对括号及算符进行处理
    if (c == '(') {
      st.push(c); // 若左括号直接压栈
    } else if (c == ')') {
      while (st.getTop() !=
             '(') { // 若非左括号，将栈中相对应括号中的元素全部出栈
        cout << st.pop();
      }
      st.pop(); // 将左括号出栈，抛弃
    } else if (c == '+' || c == '-') {
      while (!st.isEmpty() &&
             st.getTop() != '(') { // 判断栈顶元素是否为左括号，若不是则出栈
        cout << st.pop();
      }
      st.push(c); // 符号压栈
    } else if (c == '*' || c == '/') {
      while (!st.isEmpty() &&
             (st.getTop() == '*' ||
              st.getTop() == '/')) { // 输出前一个优先级高的运算符
        cout << st.pop();
      }
      st.push(c); // 符号压栈
    } else {
      cout << c;
    }
  }
  while (!st.isEmpty()) {
    cout << st.pop(); // 输出剩余符号
  }
  cout << endl;
}

bool isBracketMatched(string s) {
  Stack<char> st;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (st.isEmpty()) {
        return false;
      }
      char top = st.getTop();
      st.pop();
      if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        return false;
      }
    }
  }
  return st.isEmpty();
}

void LineEdit() { // 行编辑程序
  Stack<char> st;
  char c;
  while (cin >> c) {
    if (c == '#') {
      st.pop();
    } else if (c == '@') {
      while (!st.isEmpty()) {
        st.pop();
      }
    } else {
      st.push(c);
    }
  }
  while (!st.isEmpty()) {
    cout << st.pop();
  }
  cout << endl;
}


int main() {
  string s;
  // while (getline(cin, s)) {
  //   changeExpression(s);
  //   cout << endl;
  // }
  // while (getline(cin, s)) {
  //   cout << isBracketMatched(s) << endl;
  // }
  // LineEdit();
  return 0;
}

//栈完