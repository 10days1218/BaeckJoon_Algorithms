//https://www.acmicpc.net/problem/1389
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int adj[101][101];
int ans[101];
int n, m;

void floyd();

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }

    floyd();

    int res = INT_MAX;
    int ans;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += adj[i][j];

        if (res > sum)
        {
            res = sum;
            ans = i;
        }
    }

    cout << ans << '\n';

    return 0;
}

void floyd()
{

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;

                else if (adj[i][k] && adj[k][j])
                {
                    if (adj[i][j] == 0)
                        adj[i][j] = adj[i][k] + adj[k][j];
                    else
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
}
