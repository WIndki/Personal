#include <iostream>
#include <vector>
using namespace std;
/*二分查找树类
函数列表
HalfSearchTree() 构造函数，建立一个空二分查找树
HalfSearchTree(vector<Data> arr) 构造函数，建立一个二分查找树，元素为arr中的元素
~HalfSearchTree() 析构函数，删除一个二分查找树
void insert(Data data) 插入元素函数
int search(int data) 查找元素函数，返回元素在原队列中的位置
void InorderTravel() 中序遍历
*/
struct Data {  // 数据结构体带位置信息
  int data;
  int count;  // 元素位置
  Data(int data, int count) {
    this->data = data;
    this->count = count;
  }
  Data() {
    data = 0;
    count = 0;
  }
};

struct Node {  // 查找树树节点
  Data data;
  Node *left;
  Node *right;
  Node(Data data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class HalfSearchTree {  // 查找树类
 private:
  Node *root;
  int size;

 public:
  HalfSearchTree() {
    root = nullptr;
    size = 0;
  }
  HalfSearchTree(vector<Data> arr) {
    root = nullptr;
    size = 0;
    for (int i = 0; i < arr.size(); i++) {
      insert(arr[i]);
    }
  }
  ~HalfSearchTree() { delete root; }
  void insert(Data data) {  // 插入元素函数
    if (root == nullptr) {
      root = new Node(data);
      size++;
      return;
    }
    Node *node = root;
    while (node != nullptr) {
      if (data.data < node->data.data) {
        if (node->left == nullptr) {
          node->left = new Node(data);
          size++;
          return;
        } else {
          node = node->left;
        }
      } else if (data.data > node->data.data) {
        if (node->right == nullptr) {
          node->right = new Node(data);
          size++;
          return;
        } else {
          node = node->right;
        }
      } else {
        return;
      }
    }
  }
  int search(int data) {  // 查找元素函数，返回元素在原队列中的位置
    Node *node = root;
    while (node != nullptr) {
      if (data < node->data.data) {
        node = node->left;
      } else if (data > node->data.data) {
        node = node->right;
      } else {
        return node->data.count;
      }
    }
    return -1;
  }
  void InOrderTravel(Node *node) {  // 中序遍历
    if (node == nullptr) return;
    InOrderTravel(node->left);
    cout << node->data.data << " ";
    InOrderTravel(node->right);
  }
  void InorderTravel() { InOrderTravel(root); }
};

int main() {
  vector<Data> arr;
  arr.push_back(Data(4, 1));
  arr.push_back(Data(12, 2));
  arr.push_back(Data(125, 3));
  arr.push_back(Data(124, 4));
  arr.push_back(Data(5, 5));
  arr.push_back(Data(23, 6));
  arr.push_back(Data(81, 7));
  arr.push_back(Data(91, 8));
  arr.push_back(Data(55, 9));
  arr.push_back(Data(10, 10));
  HalfSearchTree halfSearchTree(arr);
  halfSearchTree.InorderTravel();
  cout << endl;
  cout << halfSearchTree.search(4) << endl;
  return 0;
}
//二分查找树完