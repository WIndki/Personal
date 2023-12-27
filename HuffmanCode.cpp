#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
/*
哈夫曼树
函数列表：
struct Node为哈夫曼树结点结构体
struct Compare为优先队列比较函数
struct Data为存储信息
Node *buildHuffmanTree(vector<Data> data) 建立哈夫曼树，返回结点指针
void printHuffmanCode(Node *root, string code, vector<Data> &data) 打印哈夫曼编码
存储于data中
*/
struct Node {//哈夫曼树结点结构体
  int weight;
  int pos;
  Node *left;
  Node *right;

  Node(int w, int pos) {//构造函数1
    weight = w;
    this->pos = pos;
    left = nullptr;
    right = nullptr;
  };
  Node(int w) {//构造函数2
    weight = w;
    pos=-1;
    left = nullptr;
    right = nullptr;
  };
};

struct Compare {//优先队列比较函数
  bool operator()(Node *a, Node *b) { return a->weight > b->weight; }
};

struct Data {//存储信息
  int weight;
  int pos;
  char name;
  string code;
  Data(int w, char name, int pos) {
    weight = w;
    this->name = name;
    this->pos = pos;
  }
};

Node *buildHuffmanTree(vector<Data> data) {//建立哈夫曼树
  priority_queue<Node *, vector<Node *>, Compare> pq;
  for (int i = 0; i < data.size(); i++) {
    Node *newNode = new Node(data[i].weight, data[i].pos);
    pq.push(newNode);//将结点加入优先队列
  }
  while (pq.size() > 1) {
    Node *left = pq.top();//取出权值最小的两个结点
    pq.pop();
    Node *right = pq.top();
    pq.pop();
    Node *newNode = new Node(left->weight + right->weight);//建立新结点
    newNode->left = left;//新结点连接两个权值最小的结点
    newNode->right = right;
    pq.push(newNode);//将新结点加入优先队列
  }
  return pq.top();//返回根结点
}

void printHuffmanCode(Node *root, string code, vector<Data> &data) {
  if (root == nullptr) {
    return;
  }
  if (root->left == nullptr && root->right == nullptr) {
    for (int i = 0; i < data.size(); i++) {
      if (data[i].pos == root->pos) {
        data[i].code = code;//将哈夫曼编码存入data中
        break;
      }
    }
    return;
  }
  printHuffmanCode(root->left, code + "0", data);//递归
  printHuffmanCode(root->right, code + "1", data);
}

int main() {
  vector<Data> data;
  data.push_back(Data(5, 'a',1));
  data.push_back(Data(9, 'b',2));
  data.push_back(Data(12, 'c',3));
  data.push_back(Data(13, 'd',4));
  data.push_back(Data(16, 'e',5));
  data.push_back(Data(45, 'f',6));
  Node *root = buildHuffmanTree(data);
  printHuffmanCode(root, "", data);
  for (int i = 0; i < data.size(); i++) {
    cout << data[i].name << " " << data[i].code << endl;
  }
  return 0;
}
//哈夫曼树完