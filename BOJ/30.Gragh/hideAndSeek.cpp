//https://www.acmicpc.net/problem/6118
#include <bits/stdc++.h>
using namespace std;

vector<int> g[20001];
int visited[20001];
int cost[20001];

void bfs()
{
    queue<int> q;
    int c = 0;
    visited[1] = 1;
    cost[1] = 0;

    q.push(1);

    while (!q.empty())
    {
        int e = q.front();
        q.pop();
        c = cost[e];
        for (int i = 0; i < g[e].size(); i++)
        {
            int next = g[e][i];
            if (!visited[next])
            {
                visited[next] = 1;
                q.push(next);
                cost[next] = c + 1;
            }
        }
    }
}
int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int e, v;
        cin >> e >> v;
        g[e].push_back(v);
        g[v].push_back(e);
    }

    bfs();

    int ans = 0, num = 0, cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (cost[i] > ans)
        {
            ans = cost[i];
            num = i;
            cnt = 0;
        }

        if (cost[i] == ans)
        {
            cnt++;
        }
    }

    cout << num << " " << ans << " " << cnt << '\n';
    return 0;
}