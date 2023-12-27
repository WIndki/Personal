#include <iostream>
#include <vector>
using namespace std;
/*
哈希表类
函数列表：
hashTable(int size, int skey, int counts) 构造函数
int hashFunc(int key) 哈希函数
void insert(int key) 线性探测法插入数据
int search(int key) 线性探测法查找数据
void print() 打印哈希表
*/
class hashTable {
private:
  int size;
  vector<int> table;
  int skey;
  int counts;

public:
  hashTable(int size, int skey, int counts) { // 构造函数
    this->size = size;
    this->skey = skey;
    this->counts = counts;
    table.resize(size, -999); // 初始化哈希表
    //,将哈希表的值全部初始化为-999
  }
  int hashFunc(int key) { // 哈希函数
    return key % skey;
  }
  void insert(int key) { // 线性探测法插入数据
    int index = hashFunc(key);
    while (table[index] != -999) {
      index = (index + 1) % size;
    }
    table[index] = key;
  }
  int search(int key) { // 线性探测法查找数据
    int index = hashFunc(key);
    int count = 0;
    while (table[index] != key) {
      if (table[index] == -999) {
        return -1;
      }
      index = (index + 1) % size;
      count++;
      if (count == size) {
        return -1;
      }
    }
    return index;
  }
  void print() { // 打印哈希表
    for (int i = 0; i < size; i++) {
      cout << table[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  int n;
  cin >> n;
  while (n--) {
    int size, skey, counts;
    cin >> size >> skey >> counts;
    hashTable ht(size, skey, counts);
    for (int i = 0; i < counts; i++) {
      int key;
      cin >> key;
      ht.insert(key);
    }
    ht.print();
    int key_counts;
    cin >> key_counts;
    vector<int> keys(key_counts);
    for (int i = 0; i < key_counts; i++) {
      cin >> keys[i];
    }
    for (int i = 0; i < key_counts; i++) {
      int index = ht.search(keys[i]);
      cout << index;
      if (i != key_counts - 1) {
        cout << " ";
      }
    }
  }
  return 0;
}
//哈希表完