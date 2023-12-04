#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000;
class stack{
private:
    int topPtr;
    int capacity;
    char *array;
public:
    stack(int capacity){
        this->capacity = capacity;
        topPtr = -1;
        array = new char[capacity];
    }
    stack(){
        topPtr = -1;
        capacity = MAX;
        array = new char[MAX];
    }
    ~stack(){
        delete[] array;
    }
    void push(char data){
        array[++topPtr] = data;
    }
    char top(){
        return array[topPtr];
    }
    char pop(){
        return array[topPtr--];
    }
    bool empty(){
        return topPtr == -1;
    }
};

class queue{
    private:
        int front;
        int rear;
        int capacity;
        char *array;
    public:
        queue(int capacity){
            this->capacity = capacity;
            front = -1;
            rear = -1;
            array = new char[capacity];
        }
        queue(){
            front = -1;
            rear = -1;
            capacity = MAX;
            array = new char[MAX];
        }
        ~queue(){
            delete[] array;
        }
        void push(char data){
            array[++rear] = data;
        }
        char pop(){
            return array[++front];
        }
        char Front(){
            return array[front+1];
        }
        bool empty(){
            return front == rear;
        }
};
int main() {
    int n;
    cin >> n;
    while(n--){
        string str;
        cin>>str;
        int ptr=0;
        stack s;
        queue q;
        while(str[ptr]!='&'){
            s.push(str[ptr]);
            q.push(str[ptr]);
            ptr++;
        }
        ptr++;
        int ptr_1,ptr_2;
        ptr_1=ptr_2=ptr;
        while(str[ptr_1]!='\0'){
            if(str[ptr_1]!=s.top()){
                break;
            }
            else{
                s.pop();
                ptr_1++;
            }
        }
        while (str[ptr_2]!='\0')
        {
            if(str[ptr_2]!=q.pop()){
                break;
            }
            else{
                ptr_2++;
            }
        }
        if(str[ptr_1]=='\0'&&s.empty()){
            cout<<'1'<<endl;
        }else if(str[ptr_2]=='\0'&&q.empty()){
            cout<<'2'<<endl;
        }else{
            cout<<'0'<<endl;
        }
    }

    return 0;
}


