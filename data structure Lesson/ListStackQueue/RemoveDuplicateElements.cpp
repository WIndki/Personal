#include <iostream>
#include <iomanip>
using namespace std;

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10   // 线性表存储空间的分配增量

typedef struct
{
    int *data;    // 储存空间基址
    int length;   // 存放线性表长度
    int listsize; // 当前分配的存储容量
} SqList;         // 定义顺序线性表类型

// 初始化线性表
void InitList(SqList &L)
{
    // 构造一个空的线性表L
    L.data = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L.data)
    {
        exit(0); // 存储分配失败
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
}

// 插入元素
bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
    {
        return false; // 插入位置不合法
    }
    if (L.length >= L.listsize)
    {
        int *newbase = (int *)realloc(L.data, (L.listsize + LISTINCREMENT) * sizeof(int));
        if (!newbase)
        {
            exit(0); // 存储分配失败
        }
        L.data = newbase;
        L.listsize += LISTINCREMENT;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1]; // 将第i个元素及之后的元素后移
    }
    L.data[i - 1] = e; // 插入新元素
    L.length++;        // 线性表长度加1
    return true;
}

// 删除元素
bool ListDelete(SqList &L, int i)
{
    if (i < 1 || i > L.length)
    {
        return false; // 删除位置不合法
    }
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j]; // 将第i个元素之后的元素前移
    }
    L.length--; // 线性表长度减1
    return true;
}

// 定位元素
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1; // 返回元素在线性表中的位置
        }
    }
    return 0; // 未找到元素
}

// 打印表
void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i];
        if (i < L.length - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

// 删除重复元素
void DeleteDuplicate(SqList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        for (int j = i + 1; j < L.length; j++)
        {
            if (L.data[i] == L.data[j])
            {
                ListDelete(L, j); // 删除重复元素
                j--;              // 因为删除了一个元素，所以j需要减1
            }
        }
    }
}

// 清空线性表
void ClearList(SqList &L)
{
    L.length = 0;
}

int main()
{
    int n;
    cin >> n;
    SqList L;
    InitList(L); // 初始化线性表
    for (int i = 0; i < n; i++)
    {
        int numberCount;
        cin >> numberCount;
        for (int j = 0; j < numberCount; j++)
        {
            int number;
            cin >> number;
            ListInsert(L, L.length + 1, number); // 在线性表末尾插入元素
        }
        DeleteDuplicate(L);
        PrintList(L);
        ClearList(L);
    }
    return 0;
}