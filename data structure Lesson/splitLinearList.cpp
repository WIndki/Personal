#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量

// 定义线性表结构体

// 定义线性表结构体
typedef struct SqList{
    int *data; // 存储空间基址
    int length; // 当前长度
    int listsize; // 当前分配的存储容量（以sizeof(int)为单位）
} SqList; // 结构体别名

// 初始化线性表
void initList(SqList &L) {
    L.data = (int*)malloc(LIST_INIT_SIZE*sizeof(int)); // 分配存储空间
    if(!L.data) exit(0); // 分配失败，退出程序
    L.length = 0; // 初始化长度为0
    L.listsize = LIST_INIT_SIZE; // 初始化存储容量
}


// 拆分线性表函数
void splitList(SqList A, SqList &B, SqList &C) {
    B.length = 0; // 初始化B的长度为0
    C.length = 0; // 初始化C的长度为0
    for (int i = 0; i < A.length; i++) { // 遍历线性表A
        if (*(A.data + i) >= 0) { // 如果当前元素大于等于0
            *(B.data + B.length) = *(A.data + i); // 将当前元素添加到B中
            B.length++; // B的长度加1
        } else { // 如果当前元素小于0
            *(C.data + C.length) = *(A.data + i); // 将当前元素添加到C中
            C.length++; // C的长度加1
        }
    }
}


int main() {
    SqList A, B, C;
    initList(A);
    initList(B);
    initList(C);
    int num;
    while (cin >> num) {
        *(A.data + A.length) = num;
        A.length++;
        if(cin.get()=='\n')break;
    } 
    splitList(A, B, C);
    for (int i = 0; i < B.length; i++) {
        cout << *(B.data + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < C.length; i++) {
        cout << *(C.data + i) << " ";
    }
    cout << endl;
    delete[] A.data,B.data,C.data;
    return 0;
}
