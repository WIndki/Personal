#include <iostream>
#include <queue>
using namespace std;
/*
无向图的邻接表类
函数列表
Graph(int vexnum, int arcnum) 构造函数
首先输入顶点数和边数，然后输入顶点数据，最后输入边的两个顶点与权值
int locate(char c) 用于查找顶点在数组中的位置
insert_front(char a, char b, int w) 头插法插入边，视情况使用
insert_back(char a, char b, int w) 尾插法插入边
void print() 输出邻接表
void BFS() 广度优先搜索算法
void DFS() 深度优先搜索算法
*/
struct EdgeNode {
  char vertex;
  EdgeNode *next;
  int weight;
};

struct VertexNode {
  char data;
  EdgeNode *first;
};

class Graph {
 private:
  VertexNode *GraphList;
  int vexnum;
  int arcnum;
  int locate(char c)  // 用于查找顶点在数组中的位置
  {
    for (int i = 0; i < vexnum; i++) {
      if (GraphList[i].data == c) return i;
    }
    return -1;
  }
  void insert_front(char a, char b, int w)  // 插入边函数
  {
    int a_ = locate(a);
    int b_ = locate(b);
    EdgeNode *p = new EdgeNode;  // 头插法
    p->vertex = b_;
    p->weight = w;
    p->next = GraphList[a_].first;
    GraphList[a_].first = p;
  }
  void insert_back(char a, char b, int w)  // 插入边函数
  {
    int a_ = locate(a);
    int b_ = locate(b);
    EdgeNode *p = new EdgeNode;  // 尾插法
    p->vertex = b_;
    p->weight = w;
    p->next = NULL;
    if (GraphList[a_].first == NULL)
      GraphList[a_].first = p;
    else {
      EdgeNode *q = GraphList[a_].first;
      while (q->next) q = q->next;
      q->next = p;
    }
  }

  void DFS(int v, bool visited[])  // 递归函数
  {
    visited[v] = true;                 // 标记顶点为已访问
    cout << GraphList[v].data << " ";  // 输出顶点的数据
    EdgeNode *p = GraphList[v].first;
    while (p)  // 遍历顶点的邻接表
    {
      if (!visited[p->vertex]) DFS(p->vertex, visited);  // 递归调用
      p = p->next;  // 遍历下一个邻接顶点
    }
  }

 public:
  Graph(int vexnum, int arcnum) {
    this->vexnum = vexnum;
    this->arcnum = arcnum;
    GraphList = new VertexNode[vexnum];
    for (int i = 0; i < vexnum; i++) {
      cin >> GraphList[i].data;
      GraphList[i].first = NULL;
    }
    for (int i = 0; i < arcnum; i++) {
      char a, b;
      int w;                 // 权值，可删除
      cin >> a >> b >> w;    // 权值，可删除
      insert_back(a, b, w);  // 尾插法插入无向图的两个边
      insert_back(b, a, w);
      // insert_front(a, b, w);//视情况调节尾插法或头插法
    }
  }
  void print() {
    for (int i = 0; i < vexnum; i++) {
      cout << GraphList[i].data << " ";
      EdgeNode *p = GraphList[i].first;
      while (p) {
        cout << GraphList[p->vertex].data << " " << p->weight << " ";
        p = p->next;
      }
      cout << endl;
    }
  }

  // 广度优先搜索算法
  void BFS() {
    bool visited[vexnum];  // 记录顶点是否被访问过的数组
    for (int i = 0; i < vexnum; i++) visited[i] = false;  // 初始化为未访问状态
    queue<int> q;  // 用于存储待访问的顶点的队列
    for (int i = 0; i < vexnum; i++) {
      if (!visited[i])  // 如果顶点未被访问，则进行广度优先搜索
      {
        visited[i] = true;                 // 标记顶点为已访问
        cout << GraphList[i].data << " ";  // 输出顶点的数据
        q.push(i);                         // 将顶点加入队列
        while (!q.empty()) {
          int v = q.front();                 // 取出队列的头部顶点
          q.pop();                           // 移除队列的头部顶点
          EdgeNode *p = GraphList[v].first;  // 获取顶点的邻接表头指针
          while (p) {
            if (!visited[p->vertex])  // 如果邻接顶点未被访问，则进行访问
            {
              visited[p->vertex] = true;  // 标记顶点为已访问
              cout << GraphList[p->vertex].data << " ";  // 输出顶点的数据
              q.push(p->vertex);  // 将顶点加入队列
            }
            p = p->next;  // 遍历下一个邻接顶点
          }
        }
      }
    }
  }

  void DFS() {
    bool visited[vexnum];  // 记录顶点是否被访问过的数组
    for (int i = 0; i < vexnum; i++) visited[i] = false;  // 初始化为未访问状态
    for (int i = 0; i < vexnum; i++) {  // 如果顶点未被访问，则进行深度优先搜索
      if (!visited[i]) {
        DFS(i, visited);  // 主调函数
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
    Graph g(vexnum, arcnum);
    g.print();
    g.BFS();
    cout << endl;
    g.DFS();
    cout << endl;
  }
  return 0;
}