#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct ArcNode
{
    int adjvex;
    ArcNode *next;
    char info;
};

struct VNode
{
    char data;
    ArcNode *first;
};

class Graph
{
private:
    VNode V[20];
    int vexnum;
    int arcnum;

public:
    Graph(int vexnum, int arcnum)
    {
        this->vexnum = vexnum;
        this->arcnum = arcnum;
        for (int i = 0; i < vexnum; i++)
        {
            cin >> V[i].data;
            V[i].first = NULL;
        }
        for (int i = 0; i < arcnum; i++)
        {
            char a, b;
            cin >> a >> b;
            int a_ = locate(a);
            int b_ = locate(b);
            ArcNode *p = new ArcNode;
            p->adjvex = b_;
            p->next = V[a_].first;
            V[a_].first = p;
            ArcNode *q = new ArcNode;
            q->adjvex = a_;
            q->next = V[b_].first;
            V[b_].first = q;
        }
    }
    int locate(char c){
        for(int i=0;i<vexnum;i++){
            if(V[i].data==c)
                return i;
        }
        return -1;
    }
    void print()
    {
        for (int i = 0; i < vexnum; i++)
        {
            cout << V[i].data << ":";
            ArcNode *p = V[i].first;
            while (p)
            {
                cout << p->adjvex;
                if (p->next)
                    cout << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cin>>n;
    while(n--){
    int vexnum, arcnum;
    cin >> vexnum >> arcnum;
    Graph G(vexnum, arcnum);
    G.print();
    }
    return 0;
}