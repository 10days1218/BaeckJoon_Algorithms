//https://www.acmicpc.net/problem/2660
#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int g[51][51];
int n;

void init();
int main(void)
{
    cin >> n;
    init();

    int x = 0, y = 0;

    while (1)
    {
        cin >> x >> y;
        if (x == -1 && y == -1)
            break;
        g[x][y] = 1;
        g[y][x] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];

    int minValue = INF;
    int ansList[51], idx = 0;

    for (int i = 1; i <= n; i++)
    {
        int maxValue = 0;
        for (int j = 1; j <= n; j++)
            if (maxValue < g[i][j])
                maxValue = g[i][j];

        if (maxValue <= minValue)
        {
            if (maxValue != minValue)
                idx = 0;
            ansList[idx++] = i;
            minValue = maxValue;
        }
    }

    cout << minValue << " " << idx << '\n';
    for (int i = 0; i < idx; i++)
        cout << ansList[i] << " ";
    cout << '\n';

    return 0;
}

void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = i == j ? 0 : INF;
}