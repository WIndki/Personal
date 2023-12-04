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
    void push(T x) { // 入队操作
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        data[rear] = x;
        rear = (rear + 1) % MAX_SIZE;
    }
    
    T pop() { // 出队操作
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

int main(){
    int n;
    while(cin>>n){
        int count = n;
        Queue<char> p;
        Queue<char> s;
        Queue<char> h;
        char train[100];
        cin>>train;
        int ptr=0;
        while(train[ptr]!='#'){
            if(train[ptr]=='P'){
                p.push(train[ptr]);
            }
            else if(train[ptr]=='S'){
                s.push(train[ptr]);
            }
            else if(train[ptr]=='H'){
                h.push(train[ptr]);
            }
            ptr++;
            if(train[ptr]=='#'){
                char temp[30];
                int ptr_temp=0;
                while(!p.isEmpty()){
                    temp[ptr_temp]=p.pop();
                    ptr_temp++;
                }
                while(!s.isEmpty()){
                    temp[ptr_temp]=s.pop();
                    ptr_temp++;
                }
                while(!h.isEmpty()){
                    temp[ptr_temp]=h.pop();
                    ptr_temp++;
                }
                for(int i=0;i<ptr_temp;i++){
                    cout<<temp[i];
                }
                cout<<endl;
                count--;
            }
            if(count!=0&train[ptr]=='#')ptr++;
        }
    }
    return 0;
}