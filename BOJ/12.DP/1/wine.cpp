//https://www.acmicpc.net/problem/2156
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[10001];
int wine[10001];

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> wine[i];

    for (int i = 1; i < 3 && i <= n; i++)
    {
        if (i == 1)
            dp[i] = wine[i];
        else
            dp[i] = wine[i] + wine[i - 1];
    }

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + wine[i], wine[i] + wine[i - 1] + dp[i - 3]));
    }

    cout << dp[n] << '\n';
    return 0;
}