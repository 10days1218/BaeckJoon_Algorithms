#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<int> adj[MAX];
bool visited[MAX] = {false};

void dfs(int here)
{
    visited[here] = true;
    cout << here << ' ';
    for (int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        if (!visited[there])
            dfs(there);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        cout << here << " ";

        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i];
            if (!visited[there])
            {
                q.push(there);
                visited[there] = true;
            }
        }
    }
}

int main(void)
{
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        int e, s;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 0; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(v);
    cout << '\n';
    fill_n(visited, MAX, false);
    bfs(v);

    return 0;
}