#include <iostream>
#include <cstring>

using namespace std;

class StringChunk {
private:
    char* data; // 存储串的字符数组
    int length; // 串的长度
    StringChunk* next; // 指向下一个结点的指针
public:
    StringChunk() { // 默认构造函数
        data = nullptr;
        length = 0;
        next = nullptr;
    }
    StringChunk(const char* str) { // 带参构造函数
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        next = nullptr;
    }
    ~StringChunk() { // 析构函数
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
        next = nullptr;
    }
    int getLength() { // 求串长
        return length;
    }
    int compare(StringChunk* str) { // 串比较
        int len1 = length, len2 = str->getLength();
        int minLen = len1 < len2 ? len1 : len2;
        for (int i = 0; i < minLen; i++) {
            if (data[i] < str->data[i]) {
                return -1;
            } else if (data[i] > str->data[i]) {
                return 1;
            }
        }
        if (len1 == len2) {
            return 0;
        } else if (len1 < len2) {
            return -1;
        } else {
            return 1;
        }
    }
    StringChunk* operator+(StringChunk* str) { // 串连接
        StringChunk* newChunk = new StringChunk();
        newChunk->length = length + str->getLength();
        newChunk->data = new char[newChunk->length + 1];
        strcpy(newChunk->data, data);
        strcat(newChunk->data, str->data);
        return newChunk;
    }
    StringChunk* subString(int pos, int len) { // 串子串
        if (pos < 0 || pos >= length || len <= 0 || pos + len > length) {
            return nullptr;
        }
        StringChunk* newChunk = new StringChunk();
        newChunk->length = len;
        newChunk->data = new char[len + 1];
        strncpy(newChunk->data, data + pos, len);
        newChunk->data[len] = '\0';
        return newChunk;
    }
    bool insert(int pos, StringChunk* str) { // 串插入
        if (pos < 0 || pos > length) {
            return false;
        }
        StringChunk* p = this;
        while (pos > 0 && p != nullptr) {
            p = p->next;
            pos--;
        }
        if (p == nullptr) {
            return false;
        }
        StringChunk* newChunk = new StringChunk();
        newChunk->length = str->getLength();
        newChunk->data = new char[newChunk->length + 1];
        strcpy(newChunk->data, str->data);
        newChunk->next = p->next;
        p->next = newChunk;
        return true;
    }
    bool deleteSubString(int pos, int len) { // 串删除
        if (pos < 0 || pos >= length || len <= 0 || pos + len > length) {
            return false;
        }
        StringChunk* p = this;
        while (pos > 0 && p != nullptr) {
            p = p->next;
            pos--;
        }
        if (p == nullptr) {
            return false;
        }
        StringChunk* q = p->next;
        p->next = q->next;
        delete q;
        q = nullptr;
        length -= len;
        return true;
    }

    void printString(){
        cout << data << endl;
    }
};

int main() {
    StringChunk* str1 = new StringChunk("Hello");
    StringChunk* str2 = new StringChunk("World");
    StringChunk* str3 = str1 + str2;
    cout << "str1: " ;
     str1->printString();
    cout<< " " << str1->compare(str2) << endl;
    cout << "str2: " ;
    str2->printString(); 
    cout<< " " << str2->compare(str1) << endl;
    cout << "str3: " ;
    str3->printString();
    cout<< " " << str3->compare(str1) << " " << str3->compare(str2) << endl;
    StringChunk* str4 = str3->subString(1, 8);
    cout << "str4: " << str4->getLength() << endl;
    str1->insert(2, str2);
    cout << "str1: " << str1->getLength() << endl;
    str3->deleteSubString(1, 5);
    cout << "str3: " << str3->getLength() << endl;
    delete str1;
    delete str2;
    delete str3;
    delete str4;
    return 0;
}
