//#17143
#include <bits/stdc++.h>
using namespace std;

struct SHARK
{
    int size;
    int live;
    int r;
    int c;
    int speed;
    int direction;
    int index;
};

bool operator<(SHARK t, SHARK u)
{
    return t.size < u.size;
}

int maps[101][101];
SHARK v[10001];
priority_queue<SHARK> dead[101][101];

int r, c, m;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int main(void)
{
    cin >> r >> c >> m;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int sr, sc, s, d, z;
        cin >> sr >> sc >> s >> d >> z;
        SHARK t;
        t.live = 1, t.r = sr, t.c = sc, t.speed = s, t.direction = d - 1, t.size = z, t.index = i;
        v[i] = t;
        maps[sr][sc] = i + 1;
    }

    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            if (maps[j][i] != 0)
            {
                int idx = maps[j][i] - 1;
                SHARK pick = v[idx];
                ans += pick.size;
                maps[j][i] = 0;
                v[idx].live = 0;
                break;
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (!v[j].live)
                continue;

            int s = v[j].speed;
            int dir = v[j].direction;
            int nr = v[j].r, nc = v[j].c;

            int goback = 2 * (r - 1);
            if (dir == 2 || dir == 3)
            {
                goback = 2 * (c - 1);
            }
            s %= goback;

            for (int k = 0; k < s; k++)
            {
                nr += dy[dir], nc += dx[dir];
                if (nr <= 0 || nr > r || nc <= 0 || nc > c)
                {
                    nr -= dy[dir], nc -= dx[dir];

                    if (dir == 0 || dir == 1)
                        dir = (dir + 1) % 2;
                    if (dir == 2 || dir == 3)
                        dir = (dir + 1) % 2 + 2;

                    nr += dy[dir], nc += dx[dir];
                }
            }

            v[j].r = nr, v[j].c = nc;
            v[j].direction = dir;
            dead[nr][nc].push(v[j]);
        }

        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (dead[i][j].size() == 0)
                {
                    maps[i][j] = 0;
                    continue;
                }

                SHARK tmp = dead[i][j].top();
                dead[i][j].pop();
                maps[i][j] = tmp.index + 1;

                while (!dead[i][j].empty())
                {
                    SHARK tmp = dead[i][j].top();
                    dead[i][j].pop();
                    v[tmp.index].live = 0;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}