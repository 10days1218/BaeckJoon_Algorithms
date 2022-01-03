//https://www.acmicpc.net/problem/1504
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

struct V
{
    int e;
    int cost;

    V() {}
    V(int e, int cost) : e(e), cost(cost) {}

    bool operator<(const V &v) const
    {
        return cost > v.cost;
    }
};

int n, e;
vector<V> g[801];
int dist[200002];

void dijstra(int s)
{
    fill_n(dist, 200001, INF);
    dist[s] = 0;

    priority_queue<V> pq;
    pq.push({s, 0});

    while (!pq.empty())
    {
        V p = pq.top();
        int u = p.e;
        int cost = p.cost;
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
}

int main(void)
{
    int must1, must2;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    cin >> must1 >> must2;

    dijstra(1);
    int v1 = dist[must1], v2 = dist[must2];

    if (v1 >= INF && v2 >= INF)
    {
        cout << "-1\n";
        return 0;
    }
    dijstra(n);

    if (dist[must2] >= INF && dist[must2] >= INF)
    {
        cout << "-1\n";
        return 0;
    }

    v1 += dist[must2], v2 += dist[must1];
    dijstra(must1);

    if (dist[must2] >= INF)
    {
        cout << "-1\n";
        return 0;
    }

    v1 += dist[must2], v2 += dist[must2];
    cout << min(v1, v2) << '\n';

    return 0;
}
