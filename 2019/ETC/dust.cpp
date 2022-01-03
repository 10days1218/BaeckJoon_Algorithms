//#17144
#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int maps[2][51][51];
int up_y, up_x, down_y, down_x;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

void spread(int cur)
{
    int next = (cur + 1) % 2;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (maps[cur][i][j] == -1)
                maps[next][i][j] = -1;

            else
                maps[next][i][j] = 0;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int val = maps[cur][i][j] / 5;
            int candi = 0;
            for (int k = 0; k < 4; k++)
            {
                int y = i + dx[i];
                int x = j + dy[i];

                if (y < 0 || y >= r || x < 0 || x >= c)
                    continue;

                if (maps[cur][y][x] != -1)
                {
                    maps[next][y][x] += val;
                    candi += val;
                }
            }

            if (maps[next][y][x] != -1)
                maps[next][y][x] += (maps[cur][y][x] - candi); //?
        }
    }
}

void move(int cur)
{
    for (int y = up_y - 1; y > 0; y--)
    {
        maps[cur][y][0] = maps[cur][y - 1][0];
    }

    for (int x = 0; x < c - 1; x++)
    {
        maps[cur][0][x] = maps[cur][0][x + 1];
    }

    for (int)
}
int main(void)
{
    cin >> r >> c >> t;
    up_y = -1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> maps[0][i][j];
            if (maps[0][i][j] == -1)
            {
                if (up_y == -1)
                {
                    up_y = i, up_x = j;
                }
                else
                {
                    down_y = i, down_x = j;
                }
            }
        }
    }
    int cur = 0;
    for (int i = 0; i < t; i++)
    {
        spread(cur);
        cur = (cur + 1) % 2;
        move(cur);
    }

    int ret = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (maps[cur][i][j] != -1)
            {
                ret += maps[cur][i][j];
            }
        }
    }
    return 0;
}