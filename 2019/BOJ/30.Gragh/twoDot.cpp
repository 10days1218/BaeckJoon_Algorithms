//#16929
#include <bits/stdc++.h>
using namespace std;

char maps[50][50];
int visited[50][50];
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int n, m;
int sy, sx;
bool check = false;

void dfs(int y, int x, int cnt, char color)
{
    if (check)
        return;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (!visited[ny][nx])
        {
            if (color == maps[ny][nx])
            {
                visited[ny][nx] = 1;
                dfs(ny, nx, cnt + 1, color);
            }
        }
        else
        {
            if (cnt >= 4 && ny == sy && nx == sx)
            {
                check = true;
                return;
            }
        }
    }
}
int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fill_n(visited[0], 50 * 50, 0);
            visited[i][j] = 1;
            sy = i, sx = j;
            dfs(i, j, 1, maps[i][j]);
            if (check)
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No" << '\n';

    return 0;
}