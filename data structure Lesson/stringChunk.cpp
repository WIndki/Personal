#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

const int CHUNK_SIZE = 2; // 块的大小

struct Chunk {
    char data[CHUNK_SIZE]; // 数据域
    Chunk* next; // 指针域
};

class String {
public:
    String() {
        head = tail = new Chunk(); // 初始化头结点和尾结点
        head->next = NULL;
        length = 0;
    }

    ~String() {
        Chunk* p = head;
        while (p) {
            Chunk* q = p->next;
            delete p;
            p = q;
        }
    }

    void clear() {
        Chunk* p = head->next;
        while (p) {
            Chunk* q = p->next;
            delete p;
            p = q;
        }
        head->next = NULL;
        tail = head;
        length = 0;
    }

    int size() {
        return length;
    }

    bool empty() {
        return length == 0;
    }

    char& operator[](int i) {
        if (i < 0 || i >= length) {
            throw "Index out of range";
        }
        Chunk* p = head->next;
        int k = i;
        while (k--) {
            p = p->next;
        }
        return p->data[0];
    }

    void insert(int i, char c) {
        if (i < 0 || i > length) {
            throw "Index out of range";
        }
        Chunk* p = new Chunk();
        p->data[0] = c;
        Chunk* q = head->next;
        int k = i-1;
        while(k--){
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        length++;
    }

    String& operator=(const char* s) {
        clear();
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            push_back(s[i]);
        }
        return *this;
    }

    String& operator+=(const char* s) {
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            push_back(s[i]);
        }
        return *this;
    }

    String& operator+=(const String& s) {
        Chunk* p = s.head->next;
        while (p) {
            for (int i = 0; i < CHUNK_SIZE && p->data[i]; i++) {
                push_back(p->data[i]);
            }
            p = p->next;
        }
        return *this;
    }

    String operator+(const char* s) {
        String res = *this;
        res += s;
        return res;
    }

    String operator+(const String& s) {
        String res = *this;
        res += s;
        return res;
    }

    void push_back(char c) {
        if (tail->next == NULL || strlen(tail->data) == CHUNK_SIZE) {
            Chunk* p = new Chunk();
            p->data[0] = c;
            p->next = NULL;
            tail->next = p;
            tail = p;
        } else {
            tail->data[strlen(tail->data)] = c;
        }
        length++;
    }

    void pop_back() {
        if (empty()) {
            throw "Empty string";
        }
        if (strlen(tail->data) == 1) {
            Chunk* p = head;
            while (p->next != tail) {
                p = p->next;
            }
            delete tail;
            tail = p;
            tail->next = NULL;
        } else {
            tail->data[strlen(tail->data) - 1] = '\0';
        }
        length--;
    }

    void print() {
        Chunk* p = head->next;
        while (p) {
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }

private:
    Chunk* head; // 头结点
    Chunk* tail; // 尾结点
    int length; // 串的长度
};

int main() {
    String s1;
    s1 = "Hello";
    s1.print(); // Output: Hello

    String s2;
    s2 += "World";
    s2.print(); // Output: World

    String s3 = s1 + s2;
    s3.print(); // Output: HelloWorld

    s3.pop_back();
    s3.print(); // Output: HelloWorl

    s3.push_back('d');
    s3.print(); // Output: HelloWorld

    s3[5] = ' ';
    s3.print(); // Output: Hello world

    s3[5] = 'W';
    s3.insert(5,' ');
    s3.print(); // Output: Hello World

    return 0;
}