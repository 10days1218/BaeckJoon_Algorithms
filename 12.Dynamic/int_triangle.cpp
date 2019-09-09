//#1932
#include <bits/stdc++.h>
using namespace std;

int d[501][501] = {0};
int dp[501][501] = {0};

int main(void)
{
    int n, k = 0;
    int m = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cin >> d[i][j];
    }

    dp[1][1] = d[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i - 1][j - 1] + d[i][j], dp[i - 1][j] + d[i][j]);
    }

    for (int i = 1; i <= n; i++)
        m = max(m, dp[n][i]);

    cout << m << '\n';

    return 0;
}