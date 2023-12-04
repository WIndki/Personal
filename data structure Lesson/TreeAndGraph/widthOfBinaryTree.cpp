#include <iostream>
#include <queue>
using namespace std;

// 二叉树的结点定义
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

// 计算二叉树的宽度
int calculateWidth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int maxWidth = 0;
    while (!q.empty()) {
        int size = q.size();
        maxWidth = max(maxWidth, size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
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

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string preorder;
        cin>>preorder;
        int index =0;
        TreeNode* root = buildTree(preorder,index);
        int width = calculateWidth(root);
        cout << width << endl;
    }
    return 0;
}
