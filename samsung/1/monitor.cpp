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
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<CCTV> v;
vector<int> angle;
int ans = INT_MAX;

int countBlank()
{
    int ret = 0;
    int copy_maps[8][8];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
            int r = t.x, c = t.x;
            while (r < m || c < n)
            {
                r += dy[dir], c += dx[dir];
                if (maps[r][c] == 6)
                    break;
                if (maps[r][c] == 0)
                    maps[r][c] = -1;
            }
        }

        if (t.type == 2)
        {
            int r = t.x, c = t.y;
            if (dir == 1 || dir == 3)
            {
                for (int i = 0; i < c; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }

                for (int i = c + 1; i < m; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }
            }

            if (dir == 0 || dir == 2)
            {
                for (int i = 0; i < r; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }

                for (int i = r + 1; i < n; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }
            }
        }

        if (t.type == 3)
        {
            int r = t.x, c = t.y;
            if (dir == 0)
            {
                for (int i = r - 1; i >= 0; i--)
                {
                    if (maps[i][c] == 6)
                        break;

                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }

                for (int i = c + 1; i < m; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }
            }

            if (dir == 1)
            {
                for (int i = c + 1; i < m; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }

                for (int i = r + 1; i < n; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }
            }

            if (dir == 2)
            {
                for (int i = c - 1; i >= 0; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }

                for (int i = r + 1; i < n; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }
            }

            if (dir == 3)
            {
                for (int i = c - 1; i >= 0; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }

                for (int i = r - 1; i >= 0; i--)
                {
                    if (maps[i][c] == 6)
                        break;

                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }
            }
        }

        if (t.type == 4)
        {
            int r = t.x, c = t.y;
            if (dir == 0)
            {
                for (int i = r - 1; i >= 0; i--)
                {
                    if (maps[i][c] == 6)
                        break;

                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }

                for (int i = 0; i < c; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }

                for (int i = c + 1; i < m; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }
            }

            if (dir == 1)
            {
                for (int i = c + 1; i < m; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }

                for (int i = 0; i < r; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }

                for (int i = r + 1; i < n; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }
            }

            if (dir == 2)
            {
                for (int i = 0; i < c; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }

                for (int i = c + 1; i < m; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }

                for (int i = r + 1; i < n; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }
            }

            if (dir == 3)
            {
                for (int i = 0; i < r; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }

                for (int i = r + 1; i < n; i++)
                {
                    if (maps[i][c] == 6)
                        break;
                    if (maps[i][c] == 0)
                        maps[i][c] = -1;
                }

                for (int i = 0; i < c; i++)
                {
                    if (maps[r][i] == 6)
                        break;
                    if (maps[r][i] == 0)
                        maps[r][i] = -1;
                }
            }
        }

        if (t.type == 5)
        {
            int r = t.x, c = t.y;
            for (int i = 0; i < r; i++)
            {
                if (maps[i][c] == 6)
                    break;
                if (maps[i][c] == 0)
                    maps[i][c] = -1;
            }

            for (int i = r + 1; i < n; i++)
            {
                if (maps[i][c] == 6)
                    break;
                if (maps[i][c] == 0)
                    maps[i][c] = -1;
            }

            for (int i = 0; i < c; i++)
            {
                if (maps[r][i] == 6)
                    break;
                if (maps[r][i] == 0)
                    maps[r][i] = -1;
            }

            for (int i = c + 1; i < m; i++)
            {
                if (maps[r][i] == 6)
                    break;
                if (maps[r][i] == 0)
                    maps[r][i] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
        ans = min(ans, ret);
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            angle.push_back(j);
            dfs(cnt + 1);
            angle.pop_back();
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