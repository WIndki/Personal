#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    int weight;
    int pos;
    Node *left;
    Node *right;

    Node(int w, int pos)
    {
        weight = w;
        this->pos = pos;
        left = nullptr;
        right = nullptr;
    };
    Node(int w)
    {
        weight = w;
        left = nullptr;
        right = nullptr;
    };
};
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->weight > b->weight;
    }
};

Node *buildHuffmanTree(vector<int> weights, vector<int> pos)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (int i = 0; i < weights.size(); i++)
    {
        Node *newNode = new Node(weights[i], pos[i]);
        pq.push(newNode);
    }
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node(left->weight + right->weight);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }
    return pq.top();
}

struct Output
{
    int pos;
    string code;
    int weight;
    Output(int pos, string code, int weight)
    {
        this->pos = pos;
        this->code = code;
        this->weight = weight;
    }
};

void printHuffmanCodes(Node *root, string code, vector<Output> &output)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        Output out(root->pos, code, root->weight);
        output.push_back(out);
        return;
    }
    printHuffmanCodes(root->left, code + "0", output);
    printHuffmanCodes(root->right, code + "1", output);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        vector<int> weights;
        vector<int> pos;
        for (int i = 0; i < m; i++)
        {
            int w;
            cin >> w;
            weights.push_back(w);
            pos.push_back(i + 1);
        }
        vector<Output> output;
        Node *root = buildHuffmanTree(weights, pos);
        printHuffmanCodes(root, "", output);
        for (int i = 0; i < output.size(); i++)
        {
            int j;
            for (j = 0; j < output.size(); j++)
            {
                if (output[j].pos == i + 1)
                {
                    break;
                }
            }
            cout << output[j].weight << ":" << output[j].code << endl;
        }
    }
    return 0;
}
