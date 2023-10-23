#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

const int CHUNK_SIZE = 5; // 块的大小

struct Chunk
{
    char data[CHUNK_SIZE]; // 数据域
    Chunk *next;           // 指针域
};

class String
{
private:
    Chunk *head, *tail;
    int length;

public:
    String()
    {
        head = tail = new Chunk();
        tail->next = NULL;
        length = 0;
    }

    ~String()
    {
        Chunk *p = head;
        while (p)
        {
            Chunk *q = p->next;
            delete p;
            p = q;
        }
    }

    void clear()
    {
        Chunk *p = head->next;
        while (p){
            Chunk *q = p->next;
            delete p;
            p = q;
        }
        head->next = NULL;
        tail = head;
        length = 0;
    }

    int size()
    {
        return length;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void push(char c)
    {
        Chunk *p = tail;
        if (length % CHUNK_SIZE == 0)
        {
            p->next = new Chunk();
            p = p->next;
            p->next = NULL;
            tail = p;
        }
        p->data[length % CHUNK_SIZE] = c;
        length++;
    }

    void pop()
    {
        if (isEmpty())
        {
            throw "Empty";
        }
        Chunk *p = head->next;
        int k = length / CHUNK_SIZE;
        int i = length % CHUNK_SIZE;
        if (i == 0)
            k--, i = CHUNK_SIZE;
        while (k--)
        {
            p = p->next;
        }
        p->data[i - 1] = '\0';
        length--;
    }

    String &operator+=(const String &s)
    {
        Chunk *p = s.head->next;
        while (p)
        {
            for (int i = 0; i < CHUNK_SIZE && p->data[i]; i++)
            {
                push(p->data[i]);
            }
            p = p->next;
        }
        return *this;
    }

    String &operator+=(const char *s)
    {
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            push(s[i]);
        }
        return *this;
    }

    String operator+(const String &s)
    {
        String res = *this;
        res += s;
        return res;
    }

    String operator+(const char *c)
    {
        String res = *this;
        res += c;
        return res;
    }


    String &operator=(const char *c)
    {
        clear();
        int len = strlen(c);
        for (int i = 0; i < len; i++)
        {
            push(c[i]);
        }
        return *this;
    }

    String &operator=(const String s)
    {
        clear();
        Chunk *p = s.head->next;
        while (p)
        {
            for (int i = 0; i < CHUNK_SIZE && p->data[i]; i++)
            {
                push(p->data[i]);
            }
            p = p->next;
        }
        return *this;
    }

    void printString()
    {
        Chunk *p = head->next;
        while (p)
        {
            for (int i = 0; i < CHUNK_SIZE && p->data[i]; i++)
            {
                cout << p->data[i];
            }
            p = p->next;
        }
        cout << endl;
    }

    char &operator[](int i)
    {
        if (i < 0 || i >= length)
        {
            throw "Index out of range";
        }
        Chunk *p = head->next;
        int k = i / CHUNK_SIZE;
        i = i % CHUNK_SIZE;
        if (i == 0)
            k--, i = CHUNK_SIZE;
        while (k--)
        {
            p = p->next;
        }
        return p->data[i - 1];
    }

    int KMP(const char *pattern)
    {
        int n = size();
        int m = strlen(pattern);
        if (m == 0)
        {
            return 0;
        }
        int *next = new int[m];
        next[0] = -1;
        int i = 0, j = -1;
        while (i < m - 1)
        {
            if (j == -1 || pattern[i] == pattern[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
        i = 0, j = 0;
        while (i < n && j < m)
        {
            if (j == -1 || pattern[j] == (*this)[i + 1])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        delete[] next;
        if (j == m)
        {
            return i + 1 - m;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    String s1, s2;
    s1 = "Hello";
    s2 = "World";
    String s3 = s1 + s2;
    cout << s3.size() << endl;
    s3.printString();
    s3.pop();
    cout << s3.size() << endl;
    s3.printString();
    String s4;
    s4 = (s3 + "d");
    s3 = s4;
    s3.printString();
    int pos = s3.KMP("l");
    cout << pos << endl;
    return 0;
}