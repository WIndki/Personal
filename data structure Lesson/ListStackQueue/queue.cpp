#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 队列最大容量

template <typename T>
class Queue {
private:
    T data[MAX_SIZE]; // 存储队列元素
    int front; // 队头指针
    int rear; // 队尾指针
public:
    Queue() { // 构造函数，初始化队头和队尾指针
        front = rear = 0;
    }
    bool isEmpty() { // 判断队列是否为空
        return front == rear;
    }
    bool isFull() { // 判断队列是否已满
        return (rear + 1) % MAX_SIZE == front;
    }
    void enqueue(T x) { // 入队操作
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        data[rear] = x;
        rear = (rear + 1) % MAX_SIZE;
    }
    
    T dequeue() { // 出队操作
        T element;
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }else{
            element = data[front];
        }
        front = (front + 1) % MAX_SIZE;
        return element;
    }

    T getFront() { // 获取队头元素
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data[front];
    }
    T getRear() { // 获取队尾元素
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data[(rear - 1 + MAX_SIZE) % MAX_SIZE];
    }
    int getSize() { // 获取队列长度
        return (rear - front + MAX_SIZE) % MAX_SIZE;
    }
    void printQueue() { // 打印队列元素
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.printQueue(); // 队列: 1 2 3
    q.dequeue();
    q.printQueue(); // 队列: 2 3
    cout << "队头元素: " << q.getFront() << endl; // 队头元素: 2
    cout << "队尾元素: " << q.getRear() << endl; // 队尾元素: 3
    cout << "队列长度: " << q.getSize() << endl; // 队列长度: 2
    return 0;
}
