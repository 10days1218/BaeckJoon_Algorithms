//#2206
//https://www.acmicpc.net/problem/2206
#include <bits/stdc++.h>
using namespace std;

struct POS
{
    int y;
    int x;
    int w;
};

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
char maps[1001][1001];
int dist[1001][1001][2];
int n, m;

int main(void)
{
    int ans = -1;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
        }
    }

    queue<POS> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        POS p = q.front();
        q.pop();

        if (p.y == n - 1 && p.x == m - 1)
        {
            ans = dist[p.y][p.x][p.w];
            break;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = p.y + dy[dir], nx = p.x + dx[dir], nw = p.w;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if (dist[ny][nx][p.w])
                continue;

            if (maps[ny][nx] == '0')
            {
                dist[ny][nx][p.w] = dist[p.y][p.x][p.w] + 1;
                q.push({ny, nx, p.w});
            }

            else if (maps[ny][nx] == '1' && p.w == 0)
            {
                dist[ny][nx][1] = dist[p.y][p.x][0] + 1;
                q.push({ny, nx, 1});
            }
        }
    }

    cout << ans << '\n';
    return 0;
}