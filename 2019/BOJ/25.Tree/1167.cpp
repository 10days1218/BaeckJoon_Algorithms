//https://www.acmicpc.net/problem/1167
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[100001];
bool visited[100001];
int answer, answerNode;

void dfs(int node, int cost);
int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int node;
        cin >> node;
        int cnt = 1;
        int value[2];
        while (1)
        {
            int c, w;
            cin >> c;
            if (c == -1)
                break;

            cin >> w;
            g[node].push_back({c, w});
        }
    }

    dfs(1, 0);
    answer = 0;
    fill(visited, visited + 100001, false);
    dfs(answerNode, 0);

    cout << answer << '\n';
    return 0;
}

void dfs(int node, int cost)
{
    if (visited[node])
        return;

    visited[node] = true;

    if (cost > answer)
    {
        answer = cost;
        answerNode = node;
    }

    for (int i = 0; i < g[node].size(); i++)
        dfs(g[node][i].first, g[node][i].second + cost);
}