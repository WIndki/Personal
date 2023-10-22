#include <iostream>
using namespace std;
//线性表顺序储存的C++泛型实现，动态分配内存。
template<class T>
struct SeqList{
    T *data; // 地址基元
    int length; // 存储线性表长度
    int maxSize; // 存储线性表最大长度
};

// 创建线性表
template<class T>
void CreateList(SeqList<T> &L, int n) {
    L.data = new T[n];
    cout << "请输入线性表元素：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> L.data[i];

    }
    L.length = n;
    L.maxSize = n;
}

// 插入元素
template<class T>
bool InsertList(SeqList<T> &L, int pos, int val) {
    if (pos < 1 || pos > L.length + 1) {//非法位置
        return false;
    }
    if (L.length == L.maxSize) {//判断是否需要扩容
        T *newData = new T[L.maxSize * 2];//创建长度翻倍的新数组。
        for (int i = 0; i < L.length; i++) {
            newData[i] = L.data[i];//复制原有元素。
        }
        delete[] L.data;//释放原有数组。
        L.data = newData;//指向新数组地址。
        L.maxSize *= 2;//最大长度翻倍。
    }
    for (int i = L.length; i >= pos; i--) {
        L.data[i] = L.data[i - 1];//数组元素后移
    }
    L.data[pos - 1] = val;
    L.length++;
    return true;
}

// 删除元素
template<class T>
bool DeleteList(SeqList<T> &L, int pos) {
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
template<class T>
int SearchList(SeqList<T> L, int val) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == val) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    system("chcp 65001");//设置编码格式为UTF-8
    SeqList<float> L;
    float n, pos, val;
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
