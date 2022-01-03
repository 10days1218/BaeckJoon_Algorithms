//#1753
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

struct Vertex
{
    int e;
    int cost;

    Vertex() {}
    Vertex(int e, int cost) : e(e), cost(cost) {}

    bool operator<(const Vertex &v) const
    {
        return cost > v.cost;
    }
};

int v, e, k;
vector<Vertex> g[20001];
int dist[20001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    cin >> k;

    for (int i = 0; i < e; i++)
    {
        int e1, e2, cost;
        cin >> e1 >> e2 >> cost;
        g[e1].push_back({e2, cost});
    }

    fill_n(dist, 20001, INF);
    dist[k] = 0;

    priority_queue<Vertex> pq;
    //Vertex t;
    //t.e = k, t.cost = 0;
    pq.push({k, 0});

    while (!pq.empty())
    {
        Vertex p = pq.top();
        int u = p.e;
        int c = p.cost;
        pq.pop();

        if (p.cost > dist[u])
            continue;

        for (int i = 0; i < g[u].size(); i++)
        {
            int n = g[u][i].e;
            int cost = g[u][i].cost;
            if (dist[n] > dist[u] + cost)
            {
                dist[n] = dist[u] + cost;
                pq.push({n, dist[n]});
            }
        }
    }

    for (int i = 1; i < v + 1; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
        {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}