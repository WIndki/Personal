#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
// 邻接矩阵存储无向图
/*
邻接矩阵图类
函数列表
Graph(int VertexNums, int EdgeNums) 构造函数
~Graph() 析构函数
void BFS() 广度优先遍历
void DFS() 深度优先遍历
void DFS_without_recursion() 深度优先遍历（非递归）
void print() 打印邻接矩阵
*/
class Graph {
 private:
  int **Matrix;    // 邻接矩阵
  char *Vertex;    // 顶点组
  int VertexNums;  // 顶点数
  int EdgeNums;    // 边数

  int locate(char verterName, char *vertex)  // 定位顶点位置
  {
    for (int i = 0; i < strlen(vertex); i++) {
      if (vertex[i] == verterName) {
        return i;
      }
    }
    return -1;
  }

  void DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << Vertex[v] << " ";

    for (int i = 0; i < VertexNums; i++) {
      if (Matrix[v][i] == 1 && !visited[i]) {
        DFSUtil(i, visited);
      }
    }
  }

 public:
  Graph(int VertexNums, int EdgeNums)  // 构造函数
  {
    this->VertexNums = VertexNums;
    this->EdgeNums = EdgeNums;
    this->Matrix = new int *[VertexNums];
    for (int i = 0; i < VertexNums; i++) {
      this->Matrix[i] = new int[VertexNums];
      memset(this->Matrix[i], 0, sizeof(this->Matrix[i][0]) * VertexNums);
    }
    this->Vertex = new char[VertexNums];
    for (int i = 0; i < VertexNums; i++) {
      cin >> this->Vertex[i];  // 输入顶点
    }
    cout << "请输入边：" << endl;  // 输入边
    for (int i = 0; i < EdgeNums; i++) {
      char a, b;
      cin >> a >> b;
      int x = locate(a, Vertex);  // 定位顶点所对应的位置
      int y = locate(b, Vertex);
      this->Matrix[x][y] = 1;  // 如果是有向图，只需要这一句，权值则为边的权值
      this->Matrix[y][x] = 1;
    }
  }

  ~Graph()  // 析构函数
  {
    for (int i = 0; i < VertexNums; i++) {
      delete[] this->Matrix[i];  // 释放每一行的内存
    }
    delete[] this->Matrix;  // 释放矩阵的内存
    delete[] this->Vertex;  // 释放顶点组的内存
  }

  void BFS() {
    int *isvisited =
        new int[VertexNums];  // 创建一个数组用于标记顶点是否被访问过
    memset(isvisited, 0, sizeof(isvisited[0]) * VertexNums);  // 初始化数组为0
    for (int i = 0; i < VertexNums; i++)  // 默认从第一个结点开始遍历
    {
      if (isvisited[i] == 0)  // 如果顶点未被访问过
      {
        cout << Vertex[i] << " ";  // 输出当前顶点
        isvisited[i] = 1;          // 标记当前顶点为已访问
        for (int j = 0; j < VertexNums; j++) {
          if (Matrix[i][j] == 1 &&
              isvisited[j] == 0)  // 如果顶点i和j之间有边且顶点j未被访问过
          {
            cout << Vertex[j] << " ";  // 输出顶点j
            isvisited[j] = 1;          // 标记顶点j为已访问
          }
        }
      }
    }
    cout << endl;
    delete[] isvisited;  // 释放标记数组的内存
  }

  void DFS() {
    bool *visited = new bool[VertexNums];
    for (int i = 0; i < VertexNums; i++) {
      visited[i] = false;
    }

    for (int i = 0; i < VertexNums; i++) {
      if (!visited[i]) {
        DFSUtil(i, visited);
      }
    }
    delete[] visited;
    cout << endl;
  }

  void DFS_without_recursion() {
    bool *visited = new bool[VertexNums];
    for (int i = 0; i < VertexNums; i++) {
      visited[i] = false;
    }

    stack<int> stack;
    stack.push(0);
    visited[0] = true;
    while (!stack.empty()) {
      int v = stack.top();
      cout << Vertex[v] << " ";
      stack.pop();

      for (int i = VertexNums - 1; i >= 0; i--)  // 逆序入栈
      // for (int i = 0; i < VertexNums; i++)//顺序入栈
      {
        if (Matrix[v][i] == 1 && !visited[i]) {
          stack.push(i);
          visited[i] = true;
        }
      }
    }
    delete[] visited;
  }

  void print()  // 打印邻接矩阵
  {
    for (int i = 0; i < VertexNums; i++) {
      for (int j = 0; j < VertexNums; j++) {
        cout << this->Matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  system("chcp 65001");  // 设置控制台编码为UTF-8
  int VertexNums, EdgeNums;
  cout << "请输入结点总数与边数:" << endl;
  cin >> VertexNums >> EdgeNums;
  Graph graph(VertexNums, EdgeNums);
  graph.print();
  cout << "BFS: ";
  graph.BFS();
  cout << "DFS: ";
  graph.DFS();
  cout << "DFS without recursion: ";
  graph.DFS_without_recursion();
  return 0;
}
//邻接矩阵图完