//#13460
#include <bits/stdc++.h>
using namespace std;

int n, m;
char maps[11][11];
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
struct MARBLE
{
    int rY;
    int rX;
    int bY;
    int bX;
    int count;
};
MARBLE start;

int bfs()
{
    int ret = -1;
    queue<MARBLE> q;
    bool visited[11][11][11][11] = {
        false,
    };
    visited[start.rY][start.rX][start.bY][start.bX] = true;
    q.push(start);

    while (!q.empty())
    {
        MARBLE cur = q.front();
        q.pop();
        if (cur.count > 10)
            break;

        if (maps[cur.rY][cur.rX] == 'O' && maps[cur.bY][cur.bX] != 'O')
        {
            ret = cur.count;
            break;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int next_rY = cur.rY;
            int next_rX = cur.rX;
            int next_bY = cur.bY;
            int next_bX = cur.bX;
            int next_count = cur.count;
            while (1)
            {
                if (maps[next_rY][next_rX] != '#' && maps[next_rY][next_rX] != 'O')
                {
                    next_rY += dy[dir], next_rX += dx[dir];
                }

                else
                {
                    if (maps[next_rY][next_rX] == '#')
                    {
                        next_rY -= dy[dir], next_rX -= dx[dir];
                    }
                    break;
                }
            }

            while (1)
            {
                if (maps[next_bY][next_bX] != '#' && maps[next_bY][next_bX] != 'O')
                {
                    next_bY += dy[dir], next_bX += dx[dir];
                }

                else
                {
                    if (maps[next_bY][next_bX] == '#')
                    {
                        next_bY -= dy[dir], next_bX -= dx[dir];
                    }
                    break;
                }
            }

            if (next_rY == next_bY && next_rX == next_bX)
            {
                if (maps[next_rY][next_rX] != 'O')
                {
                    int redDist = abs(next_rY - cur.rY) + abs(next_rX - cur.rX);
                    int blueDist = abs(next_bY - cur.bY) + abs(next_bX - cur.bX);
                    if (redDist > blueDist)
                    {
                        next_rY -= dy[dir], next_rX -= dx[dir];
                    }
                    else
                    {
                        next_bY -= dy[dir], next_bX -= dx[dir];
                    }
                }
            }

            if (visited[next_rY][next_rX][next_bY][next_bX] == false)
            {
                visited[next_rY][next_rX][next_bY][next_bX] = true;
                MARBLE Next;
                Next.rY = next_rY, Next.rX = next_rX, Next.bY = next_bY, Next.bX = next_bX, Next.count = cur.count + 1;
                q.push(Next);
            }
        }
    }

    return ret;
}

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> maps[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] == 'R')
            {
                start.rY = i, start.rX = j;
            }

            if (maps[i][j] == 'B')
            {
                start.bY = i, start.bX = j;
            }
        }
    }

    int ret = bfs();
    cout << ret << '\n';
    return 0;
}