#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(string input) {
    stack<TreeNode*> s;
    TreeNode* root = nullptr;
    TreeNode* cur = nullptr;
    bool isLeft = true;
    for (char c : input) {
        if (c == '(') {
            s.push(cur);
            isLeft =true;
        } else if (c == ')') {
            s.pop();
        } else if (c == ',') {
            isLeft = false;
            continue;
        } else {
            cur = new TreeNode(c);
            if (root == nullptr) {
                root = cur;
            }
            if (!s.empty()) {
                TreeNode* parent = s.top();
                if (parent->left == nullptr&&isLeft==true) {
                    parent->left = cur;
                } else {
                    parent->right = cur;
                }
            }
        }
    }
    return root;
}

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if (cur->left != nullptr) {
            q.push(cur->left);
        }
        if (cur->right != nullptr) {
            q.push(cur->right);
        }
    }
}


int main()
{
    string input;
    getline(cin,input);
    TreeNode* root = buildTree(input);
    cout<<"Binary Tree:"<<input<<endl;
    cout<<"Preorder Traversal:"<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"Inorder Traversal:"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal:"<<endl;
    postorderTraversal(root);
    cout<<endl;
    cout<<"levelorder Traversal:"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
}