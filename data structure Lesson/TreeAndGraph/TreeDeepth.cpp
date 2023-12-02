#include <iostream>
#include <queue>
using namespace std;

struct BiTNode
{
    char data;
    BiTNode *lchild, *rchild;
    BiTNode(char x) : data(x), lchild(nullptr), rchild(nullptr){};
};

void CreateBiTree(BiTNode *&root)
{
    char parent, left, right;
    queue<BiTNode *> Q;
    cin >> parent;
    if (parent == '#')
        return;
    root = new BiTNode(parent);
    Q.push(root);
    while (cin >> parent)
    {
        if (parent == '#')
            break;
        BiTNode *BT = Q.front();
        Q.pop();
        cin >> left;
        if (left == '0')
        {
            BT->lchild = NULL;
        }
        else
        {
            BT->lchild = new BiTNode(left);
            Q.push(BT->lchild);
        }
        cin >> right;
        if (right == '0')
        {
            BT->rchild = NULL;
        }
        else
        {
            BT->rchild = new BiTNode(right);
            Q.push(BT->rchild);
        }
    }
}

void swapChildren(BiTNode *&root)
{
    if (root == nullptr)
    {
        return;
    }
    BiTNode *temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    swapChildren(root->lchild);
    swapChildren(root->rchild);
}

void levelOrderTraversal(BiTNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<BiTNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BiTNode *cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->lchild != nullptr)
        {
            q.push(cur->lchild);
            cout << cur->lchild->data << " ";
        }
        else
        {
            cout << "0 ";
        }
        if (cur->rchild != nullptr)
        {
            q.push(cur->rchild);
            cout << cur->rchild->data << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
}

int TreeDeep(BiTNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int l = TreeDeep(root->lchild);
        int r = TreeDeep(root->rchild);
        int deepth = max((l + 1), (r + 1));
        return deepth;
    }
}

int main()
{
    BiTNode *T;
    CreateBiTree(T);
    // swapChildren(T);
    // levelOrderTraversal(T);
    cout << TreeDeep(T) << endl;
    return 0;
}