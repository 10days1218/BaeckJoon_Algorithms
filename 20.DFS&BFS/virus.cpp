//#2606
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool visited[101] = {false};
void dfs(int start)
{
    visited[start] = true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        int there = adj[start][i];
        if (!visited[there])
            dfs(there);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, ans = 0;
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int e, s;
        cin >> e >> s;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
        if (visited[i])
            ans++;
    cout << ans << '\n';

    return 0;
}