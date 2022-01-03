//#15683
#include <bits/stdc++.h>
using namespace std;

struct CCTV
{
    int y;
    int x;
    int type;
};

int n, m;
int maps[8][8];
int copy_maps[8][8];
const int rot_size[] = {4, 2, 4, 4, 1};
vector<CCTV> v;
vector<int> angle;
int f_cnt = 0;
int ans = INT_MAX;

void update(int dir, CCTV t)
{
    dir = dir % 4;
    int r = t.y;
    int c = t.x;

    if (dir == 0)
    {
        for (int i = c + 1; i < m; i++)
        {
            if (copy_maps[r][i] == 6)
                break;
            if (copy_maps[r][i] == 0)
                copy_maps[r][i] = -1;
        }
    }

    else if (dir == 1)
    {
        for (int i = 0; i < r; i++)
        {
            if (copy_maps[i][c] == 6)
                break;
            if (copy_maps[i][c] == 0)
                copy_maps[i][c] = -1;
        }
    }

    else if (dir == 2)
    {
        for (int i = 0; i < c; i++)
        {
            if (copy_maps[r][i] == 6)
                break;
            if (copy_maps[r][i] == 0)
                copy_maps[r][i] = -1;
        }
    }

    else if (dir == 3)
    {
        for (int i = r + 1; i < n; i++)
        {
            if (copy_maps[i][c] == 6)
                break;
            if (copy_maps[i][c] == 0)
                copy_maps[i][c] = -1;
        }
    }
}

void dfs(int cnt)
{
    if (cnt == v.size())
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maps[i][j] == 0)
                    ret++;
            }
        }

        if (ans > ret)
            ans = ret;
        return;
    }

    int backup[8][8];
    int type = v[cnt].type;

    for (int dir = 0; dir < rot_size[type]; dir++)
    {
        copy(&maps[0][0], &maps[0][0] + 8 * 8, &backup[0][0]);
        if (type == 0)
        {
            update(dir, v[cnt]);
        }

        if (type == 1)
        {
            update(dir, v[cnt]);
            update(dir + 2, v[cnt]);
        }

        if (type == 2)
        {
            update(dir, v[cnt]);
            update(dir + 1, v[cnt]);
        }

        if (type == 3)
        {
            update(dir, v[cnt]);
            update(dir + 1, v[cnt]);
            update(dir + 2, v[cnt]);
        }

        if (type == 4)
        {
            update(dir, v[cnt]);
            update(dir + 1, v[cnt]);
            update(dir + 2, v[cnt]);
            update(dir + 3, v[cnt]);
        }
        dfs(cnt + 1);
        copy(&backup[0][0], &backup[0][0] + 8 * 8, &maps[0][0]);
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
            if (maps[i][j] != 0 && maps[i][j] != 6)
            {
                CCTV t;
                t.y = i, t.x = j, t.type = maps[i][j] - 1;
                v.push_back(t);
            }
        }
    }

    dfs(0);
    cout << ans << '\n';
    return 0;
}