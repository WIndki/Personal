#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    int** adjacencyMatrix;

public:
    Graph(int n) {
        numVertices = n;
        adjacencyMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjacencyMatrix[i][j] = 0;
            }
    }
    }

    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    void printMatrix() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjacencyMatrix[i][j] ;
                if(j < numVertices - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    while(cin>>n){
    for (int i = 0; i < n; i++) {
        int numNodes, numEdges;
        cin >> numNodes >> numEdges;
        Graph graph(numNodes);
        char nodes[numNodes];
        for (int j = 0; j < numNodes; j++) {
            cin >> nodes[j];
        }    
        for (int j = 0; j < numNodes; j++) {
            char u;
            cin >> u;

            int v;
            cin >> v;

            while (v != -1) {
                graph.addEdge(u - 'a', v);
                cin >> v;
            }
        }
        graph.printMatrix();
    }
    }

    return 0;
}

