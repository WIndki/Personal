#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量

typedef struct {
    int *data; // 储存空间基址
    int length; // 存放线性表长度
    int listsize; // 当前分配的存储容量
} SqList; // 定义顺序线性表类型

// 初始化线性表
void InitList(SqList &L) {
    //构造一个空的线性表L
    L.data = (int *) malloc(LIST_INIT_SIZE  *sizeof(int));
    if (!L.data) {
        exit(0); // 存储分配失败
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
}

// 插入元素
bool ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        return false; // 插入位置不合法
    }
    if(L.length>=L.listsize){
        int *newbase = (int *) realloc(L.data, (L.listsize + LISTINCREMENT)  *sizeof(int));
        if (!newbase) {
            exit(0); // 存储分配失败
        }
        L.data = newbase;
        L.listsize += LISTINCREMENT;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1]; // 将第i个元素及之后的元素后移
    }
    L.data[i - 1] = e; // 插入新元素
    L.length++; // 线性表长度加1
    return true;
}

// 删除元素
bool ListDelete(SqList &L, int i) {
    if (i < 1 || i > L.length) {
        return false; // 删除位置不合法
    }
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j]; // 将第i个元素之后的元素前移
    }
    L.length--; // 线性表长度减1
    return true;
}

// 定位元素
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1; // 返回元素在线性表中的位置
        }
    }
    return 0; // 未找到元素
}

int main() {
    system("chcp 65001");   // 支持中文输出
    SqList L;
    InitList(L); // 初始化线性表
    int num;
    cout << "请输入元素（回车结束）：" << endl;
    while (cin>>num)
    {
        ListInsert(L, L.length + 1, num); // 在线性表末尾插入元素
        if (cin.get() == '\n')
            break;
    }
    cout << "插入元素后，线性表中的元素为：";
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
    cout << "请输入要删除的元素的位置：" << endl;
    cin >> num; // 输入要删除的元素的位置
    if(ListDelete(L, num)){ // 删除元素
    cout << "删除元素后，线性表中的元素为：";
    }else{
        cout << "删除元素失败，或位置不合法" << endl;
    }
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
    cout << "请输入要查找的元素：" << endl;
    cin >> num; // 输入要查找的元素
    int pos = LocateElem(L, num); // 查找元素30在线性表中的位置
    if (pos != 0) {
        cout << "元素在线性表中的位置为：" << pos << endl;
    } else {
        cout << "元素不在线性表中" << endl;
    }
    return 0;
}
