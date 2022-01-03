//#15684
#include <bits/stdc++.h>
using namespace std;

int n, m, h, ret;
int maps[31][11];

bool check()
{
    bool ret = true;

    for (int i = 1; i <= n; i++)
    {
        int pos = i;

        for (int j = 0; j <= h; j++)
        {
            if (maps[j][pos] == 1)
            {
                pos++;
            }
            else if (maps[j][pos - 1] == 1)
            {
                pos--;
            }
        }
        if (pos != i)
            return ret = false;
    }
    return ret;
}

void dfs(int cnt, int y, int x)
{
    if (cnt >= ret)
        return;

    if (check())
    {
        ret = cnt;
        return;
    }

    if (cnt == 3)
        return;

    for (int i = y; i <= h; i++)
    {
        for (int j = x; j < n; j++)
        {
            if (maps[i][j] == 0 && maps[i][j + 1] == 0 && maps[i][j - 1] == 0)
            {
                maps[i][j] = 1;
                dfs(cnt + 1, i, j);
                maps[i][j] = 0;
            }
        }
        x = 1;
    }
}

int main(void)
{
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        maps[a][b] = 1;
    }
    ret = 4;
    dfs(0, 1, 1);
    if (ret == 4)
        ret = -1;
    cout << ret << '\n';

    return 0;
}