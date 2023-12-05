#include <iostream>
#include <stack>
using namespace std;

struct Node{
    char name;
    int pos;
    bool visited;
    Node(int name, int pos){
        this->name = name;
        this->pos = pos;
    }
    Node(){
        this->name = 0;
        this->pos = 0;
        this->visited = false;
    }
};
class Graph {
    private:
        int numNode;
        int numEdge;
        int **adjMatrix;
        Node *nodes;
    public:
        Graph(int numNode, int numEdge,Node *nodes){
            this->numNode = numNode;
            this->numEdge = numEdge;
            this->nodes = new Node[numNode];
            for(int i = 0; i < numNode; i++){
                this->nodes[i] = nodes[i];
            }
            adjMatrix = new int*[numNode];
            for(int i = 0; i < numNode; i++){
                adjMatrix[i] = new int[numNode];
                for(int j = 0; j < numNode; j++){
                    adjMatrix[i][j] = 0;
                }
            }
        }
        ~Graph(){
            for(int i = 0; i < numNode; i++){
                delete[] adjMatrix[i];
            }
            delete[] adjMatrix;
            delete[] nodes;
        }
        void addEdge(int u, int v){
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
        void DFS(int start){
            nodes[start].visited = true;
            cout << nodes[start].name;
            for(int i = 0; i < numNode; i++){
                if(adjMatrix[start][i] == 1 && !nodes[i].visited){
                    DFS(i);
                }
            }
        }
        void print(){
            for(int i = 0; i < numNode; i++){
                for(int j = 0; j < numNode; j++){
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int locate(char c,Node *nodes, int numNode){
    for(int i = 0; i < numNode; i++){
        if(nodes[i].name == c){
            return i;
        }
    }
    return -1;
}

int main(){
    int numNode, numEdge;
    while(cin >> numNode >> numEdge){
        Node nodes[numNode];
        for(int i = 0; i < numNode; i++){
            char c;
            cin >> c;
            nodes[i] = Node(c, i);
        }
        Graph graph(numNode, numEdge, nodes);
        for(int i = 0; i < numEdge; i++){
            char u, v;
            cin >> u >> v;
            graph.addEdge(locate(u, nodes, numNode), locate(v, nodes, numNode));
        }
        graph.DFS(0);
        cout << endl;
    }
    return 0;
}