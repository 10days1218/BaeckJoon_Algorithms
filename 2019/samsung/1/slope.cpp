//#14890
#include <bits/stdc++.h>
using namespace std;

int maps[200][100];
int n, l;
int main(void)
{
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            maps[n + y][x] = maps[x][y];
        }
    }

    int i, j;
    int count = 0;
    int ret = 0;
    for (i = 0; i < n * 2; i++)
    {
        count = 1;
        for (j = 0; j < n - 1; j++)
        {
            if (maps[i][j] == maps[i][j + 1])
            {
                count++;
            }
            else if (maps[i][j] + 1 == maps[i][j + 1] && count >= l)
            {
                count = 1;
            }
            else if (maps[i][j] - 1 == maps[i][j + 1] && count >= 0)
            {
                count = (1 - l);
            }
            else
            {
                break;
            }
        }
        if (j == (n - 1) && count >= 0)
            ret++;
    }

    cout << ret << '\n';
    return 0;
}