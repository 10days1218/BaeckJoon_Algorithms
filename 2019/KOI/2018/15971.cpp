//https://www.acmicpc.net/problem/15971
#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int node;
    int total;
    int mlength;
};

vector<pair<int, int>> g[100001];
bool visited[100001];
int ans;

int main(void)
{
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n - 1; i++)
    {
        int e, v, c;
        cin >> e >> v >> c;
        g[e].push_back({v, c});
        g[v].push_back({e, c});
    }

    queue<NODE> q;
    q.push({a, 0, 0});
    visited[a] = true;
    // int mlength = 0;

    while (!q.empty())
    {
        NODE f = q.front();
        q.pop();

        if (f.node == b)
        {
            ans = f.total - f.mlength;
            break;
        }

        for (int i = 0; i < g[f.node].size(); i++)
        {
            int next = g[f.node][i].first;
            if (visited[next])
                continue;

            visited[next] = true;
            int m = f.mlength;
            if (g[f.node][i].second > f.mlength)
                m = g[f.node][i].second;

            q.push({next, f.total + g[f.node][i].second, m});
        }
    }

    cout << ans << '\n';
    return 0;
}