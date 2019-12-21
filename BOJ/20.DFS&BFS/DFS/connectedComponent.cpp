//https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>
using namespace std;

vector<int> g[1001];
bool visited[1001];

void dfs(int start);
int main(void)
{
    int n, m;
    int ans = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int e, v;
        cin >> e >> v;
        g[e].push_back(v);
        g[v].push_back(e);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}

void dfs(int start)
{
    visited[start] = true;

    for (int i = 0; i < g[start].size(); i++)
    {
        int next = g[start][i];
        if (!visited[next])
            dfs(next);
    }
}