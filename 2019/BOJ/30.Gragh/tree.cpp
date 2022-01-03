//https://www.acmicpc.net/problem/1068
#include <bits/stdc++.h>
using namespace std;

vector<int> g[51];
int visited[51];
int ans;

void bfs(int root, int deleteNode)
{
    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int node = q.front();
        int childNode = 0;
        q.pop();

        if (node == deleteNode)
            continue;

        for (int i = 0; i < g[node].size(); i++)
        {
            int next = g[node][i];
            if (next != deleteNode)
            {
                childNode++;
                q.push(next);
            }
        }
        if (childNode == 0)
            ans++;
    }
}
int main(void)
{
    int n;
    int root;
    int deleteNode;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if (p != -1)
            g[p].push_back(i);

        else
            root = i;
    }

    cin >> deleteNode;

    bfs(root, deleteNode);

    cout << ans << '\n';
    return 0;
}