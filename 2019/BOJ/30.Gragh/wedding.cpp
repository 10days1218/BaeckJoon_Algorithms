//https://www.acmicpc.net/problem/5567
#include <bits/stdc++.h>
using namespace std;

vector<int> g[501];
int visited[501];
int ans;

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = 1;

    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();

        if (f.second == 1 || f.second == 2)
        {
            ans++;
        }

        for (int i = 0; i < g[f.first].size(); i++)
        {
            int next = g[f.first][i];
            if (!visited[next])
            {
                q.push({next, f.second + 1});
                visited[next] = 1;
            }
        }
    }
}

int main(void)
{
    int n, m;

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int e, v;
        cin >> e >> v;
        g[e].push_back(v);
        g[v].push_back(e);
    }

    bfs();

    cout << ans << '\n';
    return 0;
}