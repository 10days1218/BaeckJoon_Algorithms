//#16940
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100001];
int ret[100001];
int visited[10001];
int depth[10001];
vector<int> ans;

int main(void)
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v, e;
        cin >> v >> e;
        g[v].push_back(e);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> ret[i];
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    depth[1] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        ans.push_back(depth[v]);

        for (int i = 0; i < g[v].size(); i++)
        {
            int e = g[v][i];
            if (!visited[e])
            {
                visited[e] = 1;
                q.push(e);
                depth[e] = depth[v] + 1;
            }
        }
    }
    cout << '\n';

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (ans[i] != depth[ret[i]])
        {
            flag = 0;
            break;
        }
    }

    cout << flag << '\n';

    return 0;
}