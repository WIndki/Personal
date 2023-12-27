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
int sumOfRootLeaves() 返回二叉树非叶子节点的和
int deepth() 返回二叉树的深度
int calculateWidth() 返回二叉树的宽度
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
  int nodeCount = 0; // 结点个数
  void PreOrderTravel(Node *node) {
    if (node == nullptr)
      return;
    cout << node->data << " ";
    PreOrderTravel(node->left);
    PreOrderTravel(node->right);
  }
  void InOrderTravel(Node *node) {
    if (node == nullptr)
      return;
    InOrderTravel(node->left);
    cout << node->data << " ";
    InOrderTravel(node->right);
  }
  void PostOrderTravel(Node *node) {
    if (node == nullptr)
      return;
    PostOrderTravel(node->left);
    PostOrderTravel(node->right);
    cout << node->data << " ";
  }
  int countLeafNodes(Node *node) { // 计算叶子节点个数
    if (node == nullptr)
      return 0;
    if (node->left == nullptr && node->right == nullptr)
      return 1;
    return countLeafNodes(node->left) + countLeafNodes(node->right);
  }
  void clear(Node *node) {
    if (node == nullptr)
      return;
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      node == nullptr;
      return;
    }
    clear(node->left);
    clear(node->right);
  }
  int deepth(Node *node) { // 计算二叉树深度
    if (node == nullptr)
      return 0;
    return max(deepth(node->left), deepth(node->right)) + 1;
  }

public:
  Node *createBinaryTree(string input, int &index) {
    if (index >= input.length() || input[index] == '#') {
      index++;
      return nullptr;
    }
    Node *newNode = new Node(input[index]);
    index++;
    nodeCount++; // 结点个数加1
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
  void PreOrderTravel() { // 先序遍历二叉树
    PreOrderTravel(root);
    cout << endl;
  }
  void InOrderTravel() { // 中序遍历二叉树
    InOrderTravel(root);
    cout << endl;
  }
  void PostOrderTravel() { // 后序遍历二叉树
    PostOrderTravel(root);
    cout << endl;
  }
  void LevelOrderTravel() { // 层序遍历二叉树
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *node = q.front();
      q.pop();
      cout << node->data << " ";
      if (node->left != nullptr)
        q.push(node->left);
      if (node->right != nullptr)
        q.push(node->right);
    }
    cout << endl;
  }
  int sumOfLeftLeaves() {
    return countLeafNodes(root);
  } // 返回二叉树叶子节点的和
  int sumOfRootLeaves() {
    return nodeCount - countLeafNodes(root);
  }                                     // 返回二叉树非叶子节点的和
  int deepth() { return deepth(root); } // 返回二叉树的深度
  int width() {                         // 返回二叉树的宽度
    if (root == nullptr) {
      return 0;
    }
    queue<Node *> q;
    q.push(root);
    int maxWidth = 0;
    while (!q.empty()) {
      int size = q.size();
      maxWidth = max(maxWidth, size);
      for (int i = 0; i < size; i++) {
        Node *node = q.front();
        q.pop();
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
    }
    return maxWidth;
  }
};
int main() {
  string input = "ABD##E##CF##G##";
  BinaryTree tree(input);
  tree.PreOrderTravel();
  tree.InOrderTravel();
  tree.PostOrderTravel();
  tree.LevelOrderTravel();
  cout << tree.sumOfLeftLeaves() << endl;
  cout << tree.sumOfRootLeaves() << endl;
  cout << tree.width() << endl;
  cout << tree.deepth() << endl;
  return 0;
}
// 二叉树完