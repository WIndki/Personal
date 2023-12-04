#include <iostream>
using namespace std;

struct Node
{
    int data;
    char name;
    bool isVisited;
    Node(int data, char name) : data(data), name(name){};
    Node() : data(0), name(' '){};
};

class Graph
{
private:
    int numVertices;
    int **adjacencyMatrix;

public:
    Graph(int n)
    {
        numVertices = n;
        adjacencyMatrix = new int *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjacencyMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }
    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
    void addEdge(int u, int v, int value)
    {
        adjacencyMatrix[u][v] = value;
    }
    void dfs(int start, Node *visited)
    {
        cout << visited[start].name;
        visited[start].isVisited = true;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[start][i] == 1 && !visited[i].isVisited)
            {
                cout << " ";
                dfs(i, visited);
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int numNodes, numEdges;
        cin >> numNodes >> numEdges;
        Node *nodes = new Node[numNodes];
        for (int i = 0; i < numNodes; i++)
        {
            cin >> nodes[i].name;
            nodes[i].data = i;
            nodes[i].isVisited = false;
        }
        Graph g(numNodes);
        for (int i = 0; i < numNodes; i++)
        {
            for (int j = 0; j < numNodes; j++)
            {
                int temp;
                cin >> temp;
                g.addEdge(i, j, temp);
            }
        }
        for (int i = 0; i < numNodes; i++)
        {
            g.dfs(i, nodes);
            for (int i = 0; i < numNodes; i++)
            {
                nodes[i].isVisited = false;
            }
            cout<<endl;
        }
    }
    return 0;
}
