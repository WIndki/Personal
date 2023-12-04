#include <iostream>
#include <vector>

using namespace std;

// 哈希表类
class HashTable
{
private:
    vector<int> table;     // 哈希表存储数据的数组
    int size;              // 哈希表的大小
    int hashFunc(int key); // 哈希函数

public:
    HashTable(int size);  // 构造函数
    void insert(int key); // 插入数据
    int search(int key);  // 查询数据
    void print();         // 打印哈希表
};

// 构造函数
HashTable::HashTable(int size)
{
    this->size = size;
    table.resize(size, -999);
}

// 哈希函数
int HashTable::hashFunc(int key)
{
    return key % size;
}

// 插入数据
void HashTable::insert(int key)
{
    int index = hashFunc(key);
    while (table[index] != -999)
    {
        index = (index + 1) % size; // 线性探测
    }
    table[index] = key;
}

// 查询数据
int HashTable::search(int key)
{
    int index = hashFunc(key);
    int count = 0;
    while (table[index] != key)
    {
        if (table[index] == -999)
        {
            return -1; // 没有找到
        }
        index = (index + 1) % size; // 线性探测
        count++;
        if (count == size)
        {
            return -1; // 遍历了整个哈希表，没有找到
        }
    }
    return index; // 找到了，返回下标
}

// 打印哈希表
void HashTable::print()
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (table[i] == -999)
        {
            if (count != 0)
                cout << " ";
            cout << -999;
            count++;
        }
        else
        {
            if (count != 0)
                cout << " ";
            cout << table[i];
            count++;
        }
    }
    cout << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            int r, s, t;
            cin >> r >> s >> t;
            HashTable hashTable(r);
            for (int i = 0; i < t; i++)
            {
                int num;
                cin >> num;
                hashTable.insert(num);
            }
            hashTable.print();
            int m;
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                int num;
                cin >> num;
                cout << hashTable.search(num);
                if (i < m - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
