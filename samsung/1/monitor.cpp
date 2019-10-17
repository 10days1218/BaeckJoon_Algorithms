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
const int cctvTime[] = {4, 2, 4, 4, 1};
vector<CCTV> v;
vector<int> angle;
int f_cnt = 0;
int ans = INT_MAX;

void updateBoard(int dir, CCTV t)
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

int countBlank()
{
    int ret = 0;
    fill_n(copy_maps[0], 8 * 8, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            copy_maps[i][j] = maps[i][j];
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        CCTV t = v[i];
        int dir = angle[i];

        if (t.type == 1)
        {
            updateBoard(dir, t);
        }

        if (t.type == 2)
        {
            updateBoard(dir, t);
            updateBoard(dir + 2, t);
        }

        if (t.type == 3)
        {
            updateBoard(dir, t);
            updateBoard(dir + 1, t);
        }

        if (t.type == 4)
        {
            updateBoard(dir, t);
            updateBoard(dir + 1, t);
            updateBoard(dir + 2, t);
        }

        if (t.type == 4)
        {
            updateBoard(dir, t);
            updateBoard(dir + 1, t);
            updateBoard(dir + 2, t);
            updateBoard(dir + 3, t);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (copy_maps[i][j] == 0)
                ret++;
        }
    }
    return ret;
}

void dfs(int cnt)
{
    if (cnt == v.size())
    {
        int ret = countBlank();
        if (ans > ret)
            ans = ret;
        return;
    }

    for (int j = 0; j < 4; j++)
    {
        angle.push_back(j);
        dfs(cnt + 1);
        angle.pop_back();
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
                t.y = i, t.x = j, t.type = maps[i][j];
                v.push_back(t);
            }
        }
    }

    dfs(0);
    cout << ans << '\n';
    return 0;
}