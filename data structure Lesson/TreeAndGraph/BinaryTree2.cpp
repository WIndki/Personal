#include <iostream>
#include <queue>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// 先序建立二叉树
TreeNode* buildTree(string& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == '#') {
        index++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

// 层序遍历
void levelOrderTravel(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// 先序遍历
void preorderTravel(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val;
    preorderTravel(root->left);
    preorderTravel(root->right);
}

// 中序遍历
void inorderTravel(TreeNode* root) {
    if (root == nullptr) return;
    inorderTravel(root->left);
    cout << root->val;
    inorderTravel(root->right);
}

// 后序遍历
void postorderTravel(TreeNode* root) {
    if (root == nullptr) return;
    postorderTravel(root->left);
    postorderTravel(root->right);
    cout << root->val;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略第一行的换行符
    for (int i = 0; i < n; i++) {
        string preorder;
        getline(cin, preorder);
        int index = 0;
        TreeNode* root = buildTree(preorder, index);
        levelOrderTravel(root);
        cout << endl;
        preorderTravel(root);
        cout << endl;
        inorderTravel(root);
        cout << endl;
        postorderTravel(root);
        cout << endl;
    }
    return 0;
}
