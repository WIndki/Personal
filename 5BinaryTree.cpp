#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*
二叉树类
函数列表
BinaryTree(string input) 构造函数，根据输入的字符串建立二叉树
~BinaryTree() 析构函数，释放二叉树的空间
void PreOrderTravel() 先序遍历二叉树
void InOrderTravel() 中序遍历二叉树
void PostOrderTravel() 后序遍历二叉树
void LevelOrderTravel() 层序遍历二叉树
int sumOfLeftLeaves() 返回二叉树左叶子节点的和
*/
struct Node {
  char data;
  Node *left;
  Node *right;
  Node(char data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
 private:
  Node *root;
  void PreOrderTravel(Node *node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    PreOrderTravel(node->left);
    PreOrderTravel(node->right);
  }
  void InOrderTravel(Node *node) {
    if (node == nullptr) return;
    InOrderTravel(node->left);
    cout << node->data << " ";
    InOrderTravel(node->right);
  }
  void PostOrderTravel(Node *node) {
    if (node == nullptr) return;
    PostOrderTravel(node->left);
    PostOrderTravel(node->right);
    cout << node->data << " ";
  }
  int countLeafNodes(Node *node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return countLeafNodes(node->left) + countLeafNodes(node->right);
  }
  void clear(Node *node) {
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      node == nullptr;
      return;
    }
    clear(node->left);
    clear(node->right);
  }

 public:
  Node *createBinaryTree(string input, int &index) {
    if (index >= input.length() || input[index] == '#') {
      index++;
      return nullptr;
    }
    Node *newNode = new Node(input[index]);
    index++;
    newNode->left = createBinaryTree(input, index);
    newNode->right = createBinaryTree(input, index);
    return newNode;
  }
  BinaryTree(string input) {
    int index = 0;
    root = createBinaryTree(input, index);
  }
  ~BinaryTree() {
    clear(root);
    delete root;
  }
  void PreOrderTravel() {
    PreOrderTravel(root);
    cout << endl;
  }
  void InOrderTravel() {
    InOrderTravel(root);
    cout << endl;
  }
  void PostOrderTravel() {
    PostOrderTravel(root);
    cout << endl;
  }
  void LevelOrderTravel() {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *node = q.front();
      q.pop();
      cout << node->data << " ";
      if (node->left != nullptr) q.push(node->left);
      if (node->right != nullptr) q.push(node->right);
    }
    cout << endl;
  }
  int sumOfLeftLeaves() { return countLeafNodes(root); }
};
int main() {
  string input = "ABD##E##CF###";
  BinaryTree tree(input);
  tree.PreOrderTravel();
  tree.InOrderTravel();
  tree.PostOrderTravel();
  tree.LevelOrderTravel();
  cout << tree.sumOfLeftLeaves() << endl;
  return 0;
}
//二叉树完