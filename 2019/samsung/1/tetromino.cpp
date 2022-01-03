//#145000
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[501][501] = {0};
int ans = INT_MIN;

void dfs(int x, int y, int count, int total)
{
    if (count == 4)
    {
        ans = max(ans, total);
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m) && visited[newX][newY] == 0)
            {
                visited[newX][newY] = 1;
                dfs(newX, newY, count + 1, total + a[newX][newY]);
                visited[newX][newY] = 0;
            }
        }
    }
}

void Special(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int total = 0;
        bool flag = true;
        total += a[x][y];

        for (int j = 0; j < 3; j++)
        {
            int newX = x + dx[(i + j) % 4];
            int newY = y + dy[(i + j) % 4];
            if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m))
            {
                total += a[newX][newY];
            }
            else
            {
                flag = false;
                break;
            }
        }

        if (flag)
            ans = max(ans, total);
    }
}

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 1;
            dfs(i, j, 1, a[i][j]);
            Special(i, j);
            visited[i][j] = 0;
        }
    }

    cout << ans << '\n';

    return 0;
}