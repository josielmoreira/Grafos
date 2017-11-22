#include<algorithm>
#include<climits>
#include<cstdio>
#include<queue>
//#include<vector>
#include<cstring>

#define N 100

using namespace std;

int n, maxFlow, flow, source, sink;
int residualCapacity[N][N], parent[N];

bool bfs()
{
    queue<int> q;
    q.push(source);
    memset(parent, -1, sizeof parent);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == sink) return true;
        for(int v = 0; v < n; v++) {
            if(residualCapacity[u][v] > 0 && parent[v] == -1) {
                q.push(v);
                parent[v] = u;
            }
        }
    }
    return false;
}


void augmentingPath(int v, int min_edge) {
    if(v == source) {
        flow = min_edge;
        return;
    } else if(parent[v] != -1) {
        augmentingPath(parent[v], min(min_edge, residualCapacity[parent[v]][v]));
        residualCapacity[parent[v]][v] -= flow;
        residualCapacity[v][parent[v]] += flow;
    }
}

int main() {
    int capacity, Network = 0;
    while (scanf("%d", &n) && n)
    {
        if(n == 0) break;
        scanf("%d %d %d", &source, &sink, &capacity);
        source--;
        sink--;
        memset(residualCapacity, 0, sizeof residualCapacity);
        int u, v, w;
        for(int j = 0; j < capacity; j++) {
            scanf("%d %d %d", &u, &v, &w);
            u--;
            v--;
            residualCapacity[u][v] += w;
            residualCapacity[v][u] += w;
        }

        maxFlow = 0;
        while(bfs()) {
            flow = 0;
            augmentingPath(sink, INT_MAX);
            if(flow == 0) break;
            maxFlow += flow;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", ++Network, maxFlow);
    }
}
