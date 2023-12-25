#include <iostream>
using namespace std;

/*
队列类
函数列表
queue(int size=50) 构造函数，建立一个空队列，size为队列的最大元素个数
~queue() 析构函数，删除一个队列
bool isEmpty() 判断队列是否为空，若为空则返回true，否则返回false
bool isFull() 判断队列是否为满，若为满则返回true，否则返回false
void push(T value) 将元素value压队列
T pop() 出队列，将队首元素弹出，并返回该元素的值
T getFront() 取队首元素，返回该元素值，但不删除元素
T getRear() 取队尾元素，返回该元素值，但不删除元素
int getLength() 取队列长度
void print() 打印队列
*/
template <class T>
class queue {
 private:
  T *data;
  int front;
  int rear;
  int size;

 public:
  queue(int size = 50) {  // 构造函数，建立一个空队列，size为队列的最大元素个数
    data = new T[size]{};
    front = rear = 0;
    this->size = size;
  }
  ~queue() {  // 析构函数，删除一个队列
    delete[] data;
  }
  bool isEmpty() {  // 判断队列是否为空，若为空则返回true，否则返回false
    return front == rear;
  }
  bool isFull() {  // 判断队列是否为满，若为满则返回true，否则返回false
    return (rear + 1) % size == front;
  }
  void push(T value) {  // 将元素value压队列
    if (isFull()) {
      cout << "queue full" << endl;
      return;
    }
    data[rear] = value;
    rear = (rear + 1) % size;
  }
  T pop() {  // 出队列，将队首元素弹出，并返回该元素的值
    if (isEmpty()) {
      cout << "queue empty" << endl;
      return 0;
    }
    T temp = data[front];
    front = (front + 1) % size;
    return temp;
  }
  T getFront() {  // 取队首元素，返回该元素值，但不删除元素
    if (isEmpty()) {
      cout << "queue empty" << endl;
      return 0;
    }
    return data[front];
  }
  T getRear() {  // 取队尾元素，返回该元素值，但不删除元素
    if (isEmpty()) {
      cout << "queue empty" << endl;
      return 0;
    }
    return data[(rear - 1 + size) % size];
  }
  int getLength() {  // 取队列长度
    return (rear - front + size) % size;
  }
  void print() {  // 打印队列
    if (isEmpty()) {
      cout << "queue empty" << endl;
      return;
    }
    int i = front;
    while (i != rear) {
      cout << data[i] << " ";
      i = (i + 1) % size;
    }
    cout << endl;
  }
};

int main() {
  queue<int> q;
  for (int i = 0; i < 10; i++) q.push(i);
  q.print();
  cout << q.pop() << endl;
  cout << q.getFront() << endl;
  cout << q.getRear() << endl;
  cout << q.getLength() << endl;
  q.print();
  return 0;
}