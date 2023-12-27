#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct ArcNode {
  int adjvex;
  ArcNode *next;
  int weight;
};

struct VNode {
  char data;
  ArcNode *first;
};

class Graph {
private:
  VNode V[20];
  int vexnum;
  int arcnum;

public:
  Graph(int vexnum, int arcnum) {
    this->vexnum = vexnum;
    this->arcnum = arcnum;
    vector<char> nodes(vexnum);
    for (int i = 0; i < vexnum; i++) {
      cin >> V[i].data;
      nodes[i] = V[i].data;
      V[i].first = NULL;
    }
    for (int i = 0; i < arcnum; i++) {
      char a, b;
      int c;
      cin >> a >> b >> c;
      int a_ = find(nodes.begin(), nodes.end(), a) - nodes.begin();
      int b_ = find(nodes.begin(), nodes.end(), b) - nodes.begin();
      ArcNode *p = new ArcNode;
      p->adjvex = b_;
      p->weight = c;
      p->next = V[a_].first;
      V[a_].first = p;
    }
  }

  void print() {
    for (int i = 0; i < vexnum; i++) {
      cout << V[i].data << " ";
      ArcNode *p = V[i].first;
      while (p) {
        cout << V[p->adjvex].data << " ";
        p = p->next;
      }
      cout << endl;
    }
  }

  void criticalPath() {
    int inDegree[vexnum]; // inDegree[i]表示顶点i的入度
    memset(inDegree, 0, sizeof(inDegree));
    for (int i = 0; i < vexnum; i++) {
      ArcNode *p = V[i].first;
      while (p) {
        inDegree[p->adjvex]++;
        p = p->next;
      }
    }

    stack<int> s;
    for (int i = 0; i < vexnum; i++) {
      if (inDegree[i] == 0) {
        s.push(i);
      }
    }

    int earliest[vexnum]; // earliest[i]表示顶点i的最早开始时间
    memset(earliest, 0, sizeof(earliest));
    while (!s.empty()) {
      int v = s.top();
      s.pop();

      ArcNode *p = V[v].first;
      while (p) {
        inDegree[p->adjvex]--;
        if (inDegree[p->adjvex] == 0) {
          s.push(p->adjvex);
        }

        if (earliest[v] + p->weight > earliest[p->adjvex]) {
          earliest[p->adjvex] = earliest[v] + p->weight;
        }

        p = p->next;
      }
    }

    int latest[vexnum]; // latest[i]表示顶点i的最晚开始时间
    for (int i = 0; i < vexnum; i++) {
      latest[i] = earliest[vexnum - 1];
    }

    queue<int> q;
    q.push(vexnum - 1);
    while (!q.empty()) {
      int v = q.front();
      q.pop();

      ArcNode *p = V[v].first;
      while (p) {
        if (latest[p->adjvex] - p->weight < latest[v]) {
          latest[v] = latest[p->adjvex] - p->weight;
        }

        inDegree[p->adjvex]--;
        if (inDegree[p->adjvex] == 0) {
          q.push(p->adjvex);
        }

        p = p->next;
      }
    }

    int criticalPath
        [vexnum]; // criticalPath[i]表示顶点i是否在关键路径上，1表示是，0表示不是
    memset(criticalPath, 0, sizeof(criticalPath));
    for (int i = 0; i < vexnum; i++) {
      ArcNode *p = V[i].first;
      while (p) {
        int e = earliest[i];
        int l = latest[p->adjvex] - p->weight;
        if (e == l) {
          criticalPath[i] = 1;
          break;
        }
        p = p->next;
      }
    }

    int shortestTime = earliest[vexnum - 1];
    cout << shortestTime << endl;
  }
};

int main() {
  int vexnum, arcnum;
  cin >> vexnum >> arcnum;
  Graph G(vexnum, arcnum);
  G.criticalPath();
  return 0;
}