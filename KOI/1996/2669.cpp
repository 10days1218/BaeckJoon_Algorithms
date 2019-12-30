//https://www.acmicpc.net/problem/2669
#include <bits/stdc++.h>
using namespace std;

int maps[101][101];
int main(void)
{

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;

        for (int i = y; i < Y; i++)
        {
            for (int j = x; j < X; j++)
            {
                maps[i][j] = 1;
            }
        }
    }

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (maps[i][j] == 1)
                ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}