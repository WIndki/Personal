#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
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

bool isMatching(string str) {
    stack s;
    queue q;
    
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
            q.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty() || q.empty()) {
                return false;
            }
            
            char topStack = s.top();
            char frontQueue = q.Front();
            
            if ((c == ')' && topStack != '(') ||
                (c == ']' && topStack != '[') ||
                (c == '}' && topStack != '{') ||
                (c == ')' && frontQueue != '(') ||
                (c == ']' && frontQueue != '[') ||
                (c == '}' && frontQueue != '{')) {
                return false;
            }
            
            s.pop();
            q.pop();
        }
    }
    
    return s.empty() && q.empty();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str, '#');
        
        if (isMatching(str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
