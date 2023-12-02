#include <iostream>
#include <queue>
using namespace std;
struct BiTNode
{
    char data;
    BiTNode *left, *right;
    BiTNode(char x) : data(x), left(nullptr), right(nullptr){};
    BiTNode() : data(), left(nullptr), right(nullptr) {}
};

void cleanTree(BiTNode *&root)
{
    if (root == nullptr)
    {
        return;
    }
    else if (root->data == '0')
    {
        root = nullptr;
        return;
    }
    else
    {
        cleanTree(root->left);
        cleanTree(root->right);
    }
}

BiTNode *createBinaryTree(char values[], int size)//队列创建完全二叉树
{
    BiTNode *root = new BiTNode(values[0]);
    queue<BiTNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < size)
    {
        BiTNode *curr = q.front();
        q.pop();
        //管他是不是0，先创建出来再说
        char leftVal = values[i++];
        curr->left = new BiTNode(leftVal);
        q.push(curr->left);
        char rightVal = values[i++];
        curr->right = new BiTNode(rightVal);
        q.push(curr->right);
    }
    cleanTree(root);//把data是0的孩子的直接删了
    return root;
}

void createFullBT_DFS(BiTNode *root, char numbers[], int len, int i)//递归创建完全二叉树
{
    if (i <= len)
    {
        root->data = numbers[i - 1];
        if (2 * i <= len && numbers[2 * i - 1] != '0')
        {
            root->left = new BiTNode();
            createFullBT_DFS(root->left, numbers, len, 2 * i);
        }
        if ((2 * i + 1) <= len && numbers[2 * i] != '0')
        {
            root->right = new BiTNode();
            createFullBT_DFS(root->right, numbers, len, 2 * i + 1);
        }
    }
}

int countLeaves(BiTNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    int leftLeaves = countLeaves(root->left);
    int rightLeaves = countLeaves(root->right);

    return leftLeaves + rightLeaves;
}

bool compare(BiTNode *root1, BiTNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }

    if (root1->data != root2->data)
    {
        return false;
    }

    return compare(root1->left, root2->left) && compare(root1->right, root2->right);
}

int main()
{
    char input[100];
    int nums = 0;
    for (int i = 0; i < 100; i++)
    {
        char temp;
        cin >> temp;
        if (temp == '#')
        {
            nums = i;
            break;
        }
        else
            input[i] = temp;
    }
    char values[nums];
    for (int i = 0; i < nums; i++)
    {
        values[i] = input[i];
    }
    BiTNode *root1 = createBinaryTree(values, nums);
    int leaves1 = countLeaves(root1);
    cout << leaves1 << endl;
    BiTNode *root2 = new BiTNode();
    createFullBT_DFS(root2, values, nums, 1);
    int leaves2 = countLeaves(root2);
    cout << leaves2 << endl;
    cout << compare(root1, root2) << endl;

    return 0;
}
