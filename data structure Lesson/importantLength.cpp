#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

vector<Edge> graph[MAXN];
int inDegree[MAXN];
int earliest[MAXN];
int latest[MAXN];

int criticalPath(int n) {
    queue<int> q;
    memset(earliest, 0, sizeof(earliest));
    memset(latest, INF, sizeof(latest));
    memset(inDegree, 0, sizeof(inDegree));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int to = graph[i][j].to;
            inDegree[to]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;
            inDegree[v]--;
            earliest[v] = max(earliest[v], earliest[u] + w);
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        maxTime = max(maxTime, earliest[i]);
    }

    return maxTime;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<char> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    for (int i = 0; i < m; i++) {
        char from, to;
        int weight;
        cin >> from >> to >> weight;
        int u = find(nodes.begin(), nodes.end(), from) - nodes.begin();
        int v = find(nodes.begin(), nodes.end(), to) - nodes.begin();
        graph[u].push_back(Edge(v, weight));
    }

    int shortestTime = criticalPath(n);
    cout << shortestTime << endl;


    return 0;
}
