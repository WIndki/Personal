#include <iostream>
#include "SequentialLinearList.h"
using namespace std;


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
    getchar();
}
