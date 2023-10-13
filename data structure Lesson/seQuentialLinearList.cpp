#include <iostream>
using namespace std;

typedef struct {
    int *data; // 存储线性表元素
    int length; // 存储线性表长度
    int maxSize; // 存储线性表最大长度
} SeqList;

// 创建线性表
void CreateList(SeqList &L, int n) {
    L.data = new int[n];
    cout << "请输入线性表元素：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> L.data[i];
    }
    L.length = n;
    L.maxSize = n;
}

// 插入元素
bool InsertList(SeqList &L, int pos, int val) {
    if (pos < 1 || pos > L.length + 1) {
        return false;
    }
    if (L.length == L.maxSize) {
        int *newData = new int[L.maxSize * 2];
        for (int i = 0; i < L.length; i++) {
            newData[i] = L.data[i];
        }
        delete[] L.data;
        L.data = newData;
        L.maxSize *= 2;
    }
    for (int i = L.length; i >= pos; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos - 1] = val;
    L.length++;
    return true;
}

// 删除元素
bool DeleteList(SeqList &L, int pos) {
    if (pos < 1 || pos > L.length) {
        return false;
    }
    for (int i = pos - 1; i < L.length - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.length--;
    return true;
}

// 查找元素
int SearchList(SeqList L, int val) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == val) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    SeqList L;
    int n, pos, val;
    cout << "请输入线性表长度：" << endl;
    cin >> n;
    CreateList(L, n);
    cout << "请输入要插入的元素位置和值：" << endl;
    cin >> pos >> val;
    if (InsertList(L, pos, val)) {
        cout << "插入成功！" << endl;
    } else {
        cout << "插入失败！" << endl;
    }
    cout << "请输入要删除的元素位置：" << endl;
    cin >> pos;
    if (DeleteList(L, pos)) {
        cout << "删除成功！" << endl;
    } else {
        cout << "删除失败！" << endl;
    }
    cout << "请输入要查找的元素值：" << endl;
    cin >> val;
    pos = SearchList(L, val);
    if (pos) {
        cout << "元素值为" << val << "的元素在位置" << pos << endl;
    } else {
        cout << "未找到元素值为" << val << "的元素！" << endl;
    }
    delete[] L.data;
    return 0;
}
