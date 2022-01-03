//#7569
//https://www.acmicpc.net/problem/7569
#include <bits/stdc++.h>
using namespace std;

struct POS
{
    int h;
    int y;
    int x;
    int day;
};

int m, n, h;
int maps[101][101][101];
int visited[101][101][101];
int cnt;
const int dh[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dx[] = {0, 0, 0, 0, 1, -1};
queue<POS> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> maps[i][j][k];
                if (maps[i][j][k] == 1)
                {
                    q.push({i, j, k, 0});
                }

                if (maps[i][j][k] == 0)
                {
                    cnt++;
                }
            }
        }
    }

    int tomato = 0;
    int ans;
    while (!q.empty())
    {
        POS p = q.front();
        q.pop();
        ans = p.day;

        for (int dir = 0; dir < 6; dir++)
        {
            int nh = p.h + dh[dir], ny = p.y + dy[dir], nx = p.x + dx[dir];

            if (nh < 0 || nh >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if (maps[nh][ny][nx] == 0)
            {
                maps[nh][ny][nx] = 1;
                tomato++;
                q.push({nh, ny, nx, p.day + 1});
            }
        }
    }

    if (tomato == cnt)
    {
        cout << ans << '\n';
    }

    else
    {
        cout << "-1\n";
    }

    return 0;
}