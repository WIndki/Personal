#include <iostream>
using namespace std;
/* 线性表类
函数列表：
LinearList() 构造函数
~LinearList() 析构函数
void clear() 清空线性表
bool isEmpty() 判断线性表是否为空
int getLength() 获取线性表长度
T get(int index) 获取指定位置的元素
void push_back(T value) 在末尾添加元素
void push_front(T value) 在开头添加元素
void insert(int index, T value) 在指定位置插入元素
void remove_index(int index) 删除指定位置的元素
void remove(T value) 删除指定元素
void removeAll(T value) 删除所有指定元素
int find(T value) 查找指定元素的位置
T pop_back() 出末尾元素
T pop_front() 出开头元素
void print() 打印线性表
*/
template <class T>
class LinearList
{
private:
    int size;
    int length;
    T *data;
public:
    LinearList()
    { // 构造函数
        size = 10;
        length = 0;
        data = new T[size];
    }
    ~LinearList()
    { // 析构函数
        delete[] data;
    }
    void clear()
    { // 清空线性表
        length = 0;
        size = 10;
    }
    bool isEmpty()
    { // 判断线性表是否为空
        return length == 0;
    }
    int getLength()
    { // 获取线性表长度
        return length;
    }
    T get(int index)
    { // 获取指定位置的元素
        if (index < 0 || index >= length)
        {
            cout << "index out of range" << endl;
            return 0;
        }
        return data[index];
    }
    void push_back(T value)
    { // 在末尾添加元素
        if (length >= size)
        {
            T *temp = new T[size * 2];
            for (int i = 0; i < length; i++)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            size *= 2;
        }
        data[length++] = value;
    }
    void push_front(T value)
    { // 在开头添加元素
        if (length >= size)
        {
            T *temp = new T[size * 2];
            for (int i = 0; i < length; i++)
            {
                temp[i + 1] = data[i];
            }
            delete[] data;
            data = temp;
            size *= 2;
        }
        for (int i = length; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = value;
        length++;
    }
    void insert(int index, T value)
    { // 在指定位置插入元素
        if (index < 0 || index > length)
        {
            cout << "index out of range" << endl;
            return;
        }
        if (length >= size)
        {
            T *temp = new T[size * 2];
            for (int i = 0; i < length; i++)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            size *= 2;
        }
        for (int i = length; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        length++;
    }
    void remove_index(int index)
    { // 删除指定位置的元素
        if (index < 0 || index >= length)
        {
            cout << "index out of range" << endl;
            return;
        }
        for (int i = index; i < length - 1; i++)
        {
            data[i] = data[i + 1];
        }
        length--;
    }
    void remove(T value)
    { // 删除指定元素
        for (int i = 0; i < length; i++)
        {
            if (data[i] == value)
            {
                remove_index(i);
                return;
            }
        }
        cout << "value not found" << endl;
    }
    void removeAll(T value)
    { // 删除所有指定元素
        for (int i = 0; i < length; i++)
        {
            if (data[i] == value)
            {
                remove_index(i);
                i--;
            }
        }
    }
    int find(T value)
    { // 查找指定元素的位置
        for (int i = 0; i < length; i++)
        {
            if (data[i] == value)
            {
                return i;
            }
        }
        return -1;
    }
   T findPre(T value)
    { // 查找指定元素的前驱
        for (int i = 0; i < length; i++)
        {
            if (data[i] == value)
            {
                return data[i-1];
            }
        }
        return -1;
    }
    T findNext(T value)
    { // 查找指定元素的后继
        for (int i = 0; i < length; i++)
        {
            if (data[i] == value)
            {
                return data[i+1];
            }
        }
        return -1;
    }
    T pop_back()
    { // 出末尾元素
        if (length == 0)
        {
            cout << "list is empty" << endl;
            return 0;
        }
        return data[--length];
    }
    T pop_front()
    { // 出开头元素
        if (length == 0)
        {
            cout << "list is empty" << endl;
            return 0;
        }
        T temp = data[0];
        for (int i = 0; i < length - 1; i++)
        {
            data[i] = data[i + 1];
        }
        length--;
        return temp;
    }
    void print()
    { // 打印线性表
        for (int i = 0; i < length; i++)
        {
            cout << data[i];
            if (i < length - 1)
                cout << " ";
        }
        cout << endl;
    }
};


