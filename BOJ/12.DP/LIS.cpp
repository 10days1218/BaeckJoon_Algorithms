//https://www.acmicpc.net/problem/11053
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001];
int a[1001];
int ans;
int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        int m = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                if (m < dp[j])
                {
                    m = dp[j];
                }
            }
        }
        dp[i] = m + 1;
        if (ans < dp[i])
            ans = dp[i];
    }

    cout << ans << '\n';
    return 0;
}