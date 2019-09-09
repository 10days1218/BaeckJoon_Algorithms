//#1149
#include <bits/stdc++.h>
using namespace std;

int d[1001][3] = {0};
int dp[1001][3] = {0};
int main(void)
{
    int n = 0;
    int answer = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> d[i][0] >> d[i][1] >> d[i][2];

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + d[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + d[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + d[i][2];
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';

    return 0;
}