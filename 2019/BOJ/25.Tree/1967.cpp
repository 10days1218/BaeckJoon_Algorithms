//https://www.acmicpc.net/problem/1967
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[10001];
bool visited[10001];
int answer, longestNode;

void dfs(int node, int cost);
int main(void)
{
    int n;
    cin >> n;
    n -= 1;

    while (n--)
    {
        int p, c, w;
        cin >> p >> c >> w;
        g[p].push_back({c, w});
        g[c].push_back({p, w});
    }

    dfs(1, 0);
    fill(visited, visited + 10001, false);
    answer = 0;
    dfs(longestNode, 0);

    cout << answer << '\n';
    return 0;
}

void dfs(int node, int cost)
{
    if (visited[node])
        return;

    visited[node] = true;

    if (answer < cost)
    {
        answer = cost;
        longestNode = node;
    }

    for (int i = 0; i < g[node].size(); i++)
    {
        dfs(g[node][i].first, cost + g[node][i].second);
    }
}