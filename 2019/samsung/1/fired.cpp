//#14501
#include <bits/stdc++.h>
using namespace std;

int p[16] = {0};
int t[16] = {0};
int dp[16] = {0};

int main(void)
{
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i > 0; i--)
    {
        int next = t[i] + i;
        if (next > n + 1)
        {
            dp[i] = dp[i + 1];
        }
        else
        {
            dp[i] = max(dp[i + 1], dp[next] + p[i]);
        }
    }

    cout << dp[1] << '\n';
    return 0;
}