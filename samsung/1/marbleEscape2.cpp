//#13460
#include <bits/stdc++.h>
using namespace std;

struct INFO
{
    int ry, rx, by, bx, count;
};

INFO start;
char maps[10][11];

int bfs()
{
    int ret = -1;
    const int dy[] = {-1, 1, 0, 0};
    const int dx[] = {0, 0, -1, 1};
    int visited[10][10][10][10] = {
        0,
    };

    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;

    while (!q.empty())
    {
        INFO cur = q.front();
        q.pop();
        if (cur.count > 10)
            break;

        if (maps[cur.ry][cur.rx] == 'O' && maps[cur.by][cur.bx] != 'O')
        {
            ret = cur.count;
            break;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            while (1)
            {
                if (maps[next_ry][next_rx] != '#' && maps[next_ry][next_rx] != 'O')
                {
                    next_ry += dy[dir], next_rx += dx[dir];
                }
                else
                {
                    if (maps[next_ry][next_rx] == '#')
                    {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    break;
                }
            }

            while (1)
            {
                if (maps[next_by][next_bx] != '#' && maps[next_by][next_bx] != 'O')
                {
                    next_by += dy[dir], next_bx += dx[dir];
                }
                else
                {
                    if (maps[next_by][next_bx] == '#')
                    {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }

            if (next_ry == next_by && next_rx == next_bx)
            {
                if (maps[next_ry][next_rx] != 'O')
                {
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    if (red_dist > blue_dist)
                    {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    else
                    {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                }
            }

            if (visited[next_ry][next_rx][next_by][next_bx] == 0)
            {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }
    return ret;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> maps[i];
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (maps[y][x] == 'R')
            {
                start.ry = y, start.rx = x;
            }
            if (maps[y][x] == 'B')
            {
                start.by = y, start.bx = x;
            }
        }
    }

    int ret = bfs();
    cout << ret << '\n';
    return 0;
}