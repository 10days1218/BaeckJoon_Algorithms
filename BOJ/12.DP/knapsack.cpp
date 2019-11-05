//https://www.acmicpc.net/problem/12865
#include <bits/stdc++.h>
using namespace std;

struct ITEM
{
    int w;
    int v;

    // bool operator<(const struct ITEM &item) const
    // {
    //     return w < item.w;
    // }
};

int n, k;
ITEM item[101];
int dp[101][100001];

int main(void)
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> item[i].w >> item[i].v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (item[i].w > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i].w] + item[i].v);
            }
        }
    }

    cout << dp[n][k] << '\n';
    return 0;
}