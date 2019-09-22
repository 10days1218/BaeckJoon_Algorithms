//#15684
#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int totalCount = 0;
bool maps[31][11] = {false};
bool flag = true;
void dfs(int y, int count)
{
    if (flag)
        return;

    if (totalCount == count)
    {
        //bool check = true;
        for (int i = 1; i <= n; i++)
        {
            int ans = i;
            for (int j = 0; j < h; j++)
            {
                if (maps[j][i])
                    ans++;
                if (!maps[j][i] && ans > 1 && maps[j][ans - 1])
                    ans--;
            }
            if (ans != i)
            {
                flag = false;
                break;
            }
        }
        return;
    }

    for (int i = y; i < h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (!maps[y][j - 1] && !maps[y][j] && !maps[y][j + 1])
            {
                maps[i][j] = true;
                dfs(i, count + 1);
                maps[i][j] = false;
            }
        }
    }
}
int main(void)
{
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        maps[a - 1][b] = true;
    }

    for (int i = 0; i <= 3; i++)
    {
        totalCount = i;
        dfs(0, 0);
        if (flag)
        {
            cout << totalCount << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}