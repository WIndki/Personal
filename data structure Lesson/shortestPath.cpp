#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    private:
        int** G;	 			//邻接矩阵 
        int* isvisited;			//访问数组 
        int Nv;					//顶点数
        int Ne;					//边数 
    public:
        //构造函数 
        Graph(int nv , int ne){
            this->Nv = nv;
            this->Ne = ne;
            this->G = new int*[nv+1];
            this->isvisited = new int[nv+1];
            memset(isvisited,0,sizeof(isvisited[0])*(nv+1));
            for(int i = 0 ; i < nv+1 ; i++){
                G[i] = new int[nv+1];
                memset(G[i],0,sizeof(G[i][0])*(nv+1));
            }
            for(int i = 0 ; i < ne ; i++){
                char a,b;
                int c;
                cin>>a>>b>>c;
                int a_ = a - 'A' + 1;
                int b_= b - 'A' + 1;
                this->G[a_][b_] = c;
                this->G[b_][a_] = c;
            }
        }
        
        //重置函数
        void reset(){
            memset(this->isvisited,0,sizeof(this->isvisited[0])*(this->Nv+1));
        }
        
        void print(){
            for (int i = 1; i <= Nv; i++) {
                for (int j = 1; j <= Nv; j++) {
                    cout << G[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        // 最短路径算法
        int shortestDistance(int start, int end) {
            this->isvisited = new int[Nv+1];
            memset(isvisited,0,sizeof(isvisited[0])*(Nv+1));
            vector<int> dist(Nv + 1, 255); // 初始化距离数组为最大整数
            dist[start] = 0; // 起点到自身的距离为0
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push(make_pair(0, start)); // 将起点加入优先队列
            
            while (!pq.empty()) {
                int u = pq.top().second; // 取出当前距离最小的顶点
                pq.pop();
                
                if (isvisited[u]) continue; // 如果该顶点已经访问过，则跳过
                
                isvisited[u] = 1; // 标记该顶点为已访问
                
                for (int v = 1; v <= Nv; v++) {
                    if (G[u][v] != 0 && dist[u] + G[u][v] < dist[v]) {
                        dist[v] = dist[u] + G[u][v]; // 更新最短距离
                        pq.push(make_pair(dist[v], v)); // 将更新后的顶点加入优先队列
                    }
                }
            }
            return dist[end];
        }
        

        
};

int main(){
    system("chcp 65001"); // 设置控制台编码为UTF-8
    int nv,ne;
    cin>>nv>>ne;
	char alis[nv];
	for(int i=0;i<nv;i++)cin>>alis[i];
    Graph graph(nv,ne);
    int minSum = 50; // 初始化最小路径和为最大整数
    int minIndex = -1; // 初始化最小路径和对应的顶点下标为-1
    for (int i = 1; i <= nv; i++) {
        int sum = 0; // 当前顶点到其余顶点最短路径的和
        
        for (int j = 1; j <= nv; j++) {
            if (i != j) {
                sum += graph.shortestDistance(i, j); // 计算当前顶点到其他顶点的最短路径和
            }
        }
        
        if (sum < minSum) {
            minSum = sum; // 更新最小路径和
            minIndex = i; // 更新最小路径和对应的顶点下标
        }
    }
    cout << alis[minIndex-1] << endl;
    
    return 0;
}
