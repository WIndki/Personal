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
            int a_ = a - 'A';
            int b_ = b - 'A';
            ArcNode *p = new ArcNode;
            p->adjvex = b_;
            p->next = NULL;
            if (V[a_].first == NULL)
            {
                V[a_].first = p;
            }
            else
            {
                ArcNode *q = V[a_].first;
                while (q->next != NULL)
                {
                    q = q->next;
                }
                q->next = p;
            }
            ArcNode *q = new ArcNode;
            q->adjvex = a_;
            q->next = NULL;
            if (V[b_].first == NULL)
            {
                V[b_].first = q;
            }
            else
            {
                ArcNode *r = V[b_].first;
                while (r->next != NULL)
                {
                    r = r->next;
                }
                r->next = q;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < vexnum; i++)
        {
            cout << V[i].data << " ";
            ArcNode *p = V[i].first;
            while (p)
            {
                cout << V[p->adjvex].data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
    void BFS()
    {
        bool visited[20] = {false};
        queue<int> q;
        char output[vexnum];
        int count = 0;
        for (int i = 0; i < vexnum; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;

                q.push(i);

                while (!q.empty())
                {
                    int vertex = q.front();
                    q.pop();
                    output[count] = V[vertex].data;
                    count++;
                    ArcNode *p = V[vertex].first;
                    while (p)
                    {
                        int adjVertex = p->adjvex;
                        if (!visited[adjVertex])
                        {
                            visited[adjVertex] = true;
                            q.push(adjVertex);
                        }
                        p = p->next;
                    }
                }
            }
        }
        for (int i = 0; i < vexnum; i++)
        {
            cout << output[i];
            if (i < vexnum - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int vexnum, arcnum;
    cin >> vexnum >> arcnum;
    Graph G(vexnum, arcnum);
    G.BFS();
    return 0;
}