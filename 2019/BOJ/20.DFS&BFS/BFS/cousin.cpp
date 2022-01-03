//https://www.acmicpc.net/problem/2644
#include <bits/stdc++.h>
using namespace std;

vector<int> g[101];
int m, n, x, y;
bool visited[101];

int main(void)
{
    int ans = -1;
    cin >> n;
    cin >> x >> y;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int p, c;
        cin >> p >> c;
        g[p].push_back(c);
        g[c].push_back(p);
    }

    queue<pair<int, int>> q;
    q.push({x, -1});
    visited[x] = true;

    while (!q.empty())
    {
        pair<int, int> hear = q.front();
        q.pop();
        hear.second++;
        if (hear.first == y)
        {
            ans = hear.second;
            break;
        }

        for (int i = 0; i < g[hear.first].size(); i++)
        {
            int next = g[hear.first][i];
            if (!visited[next])
            {
                q.push({next, hear.second});
                visited[next] = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}