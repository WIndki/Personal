#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
  int **G;        // 邻接矩阵
  int *isvisited; // 访问数组
  int Nv;         // 顶点数
  int Ne;         // 边数
public:
  // 构造函数
  Graph(int nv, int ne) {
    this->Nv = nv;
    this->Ne = ne;
    this->G = new int *[nv + 1];
    this->isvisited = new int[nv + 1];
    memset(isvisited, 0, sizeof(isvisited[0]) * (nv + 1));
    for (int i = 0; i < nv + 1; i++) {
      G[i] = new int[nv + 1];
      memset(G[i], 0, sizeof(G[i][0]) * (nv + 1));
    }
    for (int i = 0; i < ne; i++) {
      char a, b;
      int c;
      cin >> a >> b >> c;
      int a_ = a - 'A' + 1;
      int b_ = b - 'A' + 1;
      this->G[a_][b_] = c;
      this->G[b_][a_] = c;
    }
  }

  // 重置函数
  void reset() {
    memset(this->isvisited, 0, sizeof(this->isvisited[0]) * (this->Nv + 1));
  }

  void print() {
    for (int i = 1; i <= Nv; i++) {
      for (int j = 1; j <= Nv; j++) {
        cout << G[i][j] << " ";
      }
      cout << endl;
    }
  }

  int kruskal() {
    // 定义边的结构体
    struct Edge {
      int u, v, weight;
      bool operator<(const Edge &other) const { return weight < other.weight; }
    };

    // 初始化边集合
    vector<Edge> edges;
    for (int i = 1; i <= Nv; i++) {
      for (int j = i + 1; j <= Nv; j++) {
        if (G[i][j] != 0) {
          Edge e;
          e.u = i;
          e.v = j;
          e.weight = G[i][j];
          edges.push_back(e);
        }
      }
    }

    // 按权值从小到大排序
    sort(edges.begin(), edges.end());

    // 初始化并查集
    vector<int> parent(Nv + 1);
    for (int i = 1; i <= Nv; i++) {
      parent[i] = i;
    }

    // 计算最小生成树的权值合
    int sumWeight = 0;
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i].u;
      int v = edges[i].v;
      int weight = edges[i].weight;

      // 判断u和v是否在同一个连通分量中
      while (parent[u] != u) {
        u = parent[u];
      }
      while (parent[v] != v) {
        v = parent[v];
      }

      // 如果u和v不在同一个连通分量中，则将它们合并，并加上权值
      if (u != v) {
        parent[v] = u;
        sumWeight += weight;
      }
    }

    return sumWeight;
  }
};

int main() {
  int nv, ne;
  cin >> nv >> ne;
  char alis[nv];
  for (int i = 0; i < nv; i++)
    cin >> alis[i];
  Graph graph(nv, ne);
  cout << graph.kruskal() << endl;
  return 0;
}