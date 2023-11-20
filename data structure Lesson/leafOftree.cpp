#include <iostream>
#include <queue>
using namespace std;

struct BiTNode{
    char data;
    BiTNode *lchild, *rchild;
    BiTNode() : data(), lchild(nullptr), rchild(nullptr) {};
};

BiTNode* CreateTree(queue<char> q){
    BiTNode *root = new BiTNode();
    int val = q.front();
    q.pop();
    if (val == '#') {
        return root;
    }
    root->data = val;
    root->lchild = CreateTree(q);
    root->rchild = CreateTree(q);
}