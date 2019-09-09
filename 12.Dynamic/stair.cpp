//#2579
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int d[300] = {0};
    int dp[300] = {0};
    int count = 0;
    for (int i = 0; i < n; i++)
        cin >> d[i];

    dp[0] = d[0];
    dp[1] = max(d[1], d[0] + d[1]);
    dp[2] = max(d[0] + d[2], d[1] + d[2]);

    for (int i = 3; i < n; i++)
        dp[i] = max(dp[i - 2] + d[i], dp[i - 3] + d[i - 1] + d[i]);

    cout << dp[n - 1] << '\n';

    return 0;
}