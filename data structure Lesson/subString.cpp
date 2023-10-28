#include <iostream>
using namespace std;

size_t strlen(const char *str)
{
    size_t len = 0;
    while (*str++)
    {
        ++len;
    }
    return len;
}

char *strcpy(char *dest, const char *src)
{
    char *ret = dest;
    while ((*dest++ = *src++) != '\0')
        ;
    return ret;
}

char *strcat(char *dest, const char *src)
{
    char *ret = dest;
    while (*dest)
    {
        ++dest;
    }
    while ((*dest++ = *src++) != '\0')
        ;
    return ret;
}

char *strncpy(char *strDest, const char *strSrc, int num)
{
    char *strDestcopy = strDest;
    while ((num--) && (*strDest++ = *strSrc++) != '\0')
        ;
    if (num > 0)
    {
        while (--num)
        {
            *strDest++ = '\0';
        }
    }
    return strDestcopy;
}

int strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

class String
{
private:
    char *str;
    int length;

public:
    String()
    {
        str = new char[1];
        str[0] = '\0';
        length = 0;
    }
    String(const char *s)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    String(const String &s)
    {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }
    ~String()
    {
        delete[] str;
    }
    String &operator=(const char *s)
    {
        if (str != s)
        {
            delete[] str;
            length = strlen(s);
            str = new char[length + 1];
            strcpy(str, s);
        }
        return *this;
    }
    String &operator=(const String &s)
    {
        if (str != s.str)
        {
            delete[] str;
            length = s.length;
            str = new char[length + 1];
            strcpy(str, s.str);
        }
        return *this;
    }
    char &operator[](int i)
    {
        return str[i];
    }
    String operator+(const char *s)
    {
        String temp;
        temp.length = length + strlen(s);
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s);
        return temp;
    }
    String operator+(const String &s)
    {
        String temp;
        temp.length = length + s.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }
    bool operator==(const char *s)
    {
        return strcmp(str, s) == 0;
    }
    bool operator==(const String &s)
    {
        return strcmp(str, s.str) == 0;
    }
    bool operator!=(const char *s)
    {
        return strcmp(str, s) != 0;
    }
    bool operator!=(const String &s)
    {
        return strcmp(str, s.str) != 0;
    }
    int size()
    {
        return length;
    }
    friend ostream &operator<<(ostream &os, const String &s)
    {
        os << s.str;
        return os;
    }
    void SubString(String &Sub, int pos, int len)
    {
        if (pos < 0 || pos >= length || len < 0 || pos + len > length)
        {
            Sub = "";
            return;
        }
        char *temp = new char[len + 1];
        strncpy(temp, str + pos, len);
        temp[len] = '\0';
        Sub = temp;
        delete[] temp;
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
            if (j == -1 || pattern[j] == str[i])
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
            return 0;
        }
    }
    int compare(char *t)
    {
        int i = 0;
        while (str[i] != '\0' && t[i] != '\0')
        {
            if (str[i] != t[i])
            {
                return str[i] - t[i];
            }
            i++;
        }
        if (str[i] == '\0' && t[i] == '\0')
        {
            return 0;
        }
        else
        {
            return str[i] - t[i];
        }
    }
    void printString()
    {
        cout << str << endl;
    }
};

int main()
{
    String s1, s2;
    char s1_[30];
    int pos, length;
    cin.getline(s1_, 30);
    cin >> pos >> length;
    s1 = s1_;
    s1.SubString(s2, pos - 1, length);
    s2.printString();
    return 0;
}
