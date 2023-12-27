#include <cstring>
#include <iostream>
using namespace std;

class graph {
private:
  int G[20][20];
  int vexnum;
  int arcnum;
  char *vexs;
  int locate(char *vex, char c) {
    for (int i = 0; i < vexnum; i++) {
      if (vex[i] == c) {
        return i;
      }
    }
    return -1;
  }

public:
  graph(int vexnum, int arcnum) {
    this->vexnum = vexnum;
    this->arcnum = arcnum;
    vexs = new char[vexnum];
    for (int i = 0; i < vexnum; i++) {
      cin >> vexs[i];
    }
    memset(G, 0, sizeof(G));
    for (int i = 0; i < arcnum; i++) {
      char a, b;
      int c;
      cin >> a >> b >> c;
      int a_ = locate(vexs, a);
      int b_ = locate(vexs, b);
      G[a_][b_] = c;
    }
  }
  void criticalPath() {
    int inDegree[vexnum];
    memset(inDegree, 0, sizeof(inDegree));
    for (int i = 0; i < vexnum; i++) {
      for (int j = 0; j < vexnum; j++) {
        if (G[i][j] != 0) {
          inDegree[j]++;
        }
      }
    }
    int ve[vexnum];
    memset(ve, 0, sizeof(ve));
    for (int i = 0; i < vexnum; i++) {
      if (inDegree[i] == 0) {
        ve[i] = 0;
      }
    }
    for (int i = 0; i < vexnum; i++) {
      for (int j = 0; j < vexnum; j++) {
        if (G[i][j] != 0) {
          if (ve[i] + G[i][j] > ve[j]) {
            ve[j] = ve[i] + G[i][j];
          }
        }
      }
    }
    int vl[vexnum];
    memset(vl, ve[vexnum - 1], sizeof(vl));
    for (int i = vexnum - 1; i >= 0; i--) {
      for (int j = vexnum - 1; j >= 0; j--) {
        if (G[i][j] != 0) {
          if (vl[j] - G[i][j] < vl[i]) {
            vl[i] = vl[j] - G[i][j];
          }
        }
      }
    }
    for (int i = 0; i < vexnum; i++) {
      for (int j = 0; j < vexnum; j++) {
        if (G[i][j] != 0) {
          int e = ve[i];
          int l = vl[j] - G[i][j];
          if (e == l) {
            cout << vexs[i] << "->" << vexs[j] << endl;
          }
        }
      }
    }
  }
};

int main() {
  int n;
  cin >> n;
  while (n--) {
    int vexnum, arcnum;
    cin >> vexnum >> arcnum;
    graph g(vexnum, arcnum);
    g.criticalPath();
  }
  return 0;
}