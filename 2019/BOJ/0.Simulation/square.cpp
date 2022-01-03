//https://www.acmicpc.net/problem/8320
#include <bits/stdc++.h>
using namespace std;

int cnt[10001];

int main(void)
{
    int n;
    int ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n / i; j++)
        {
            cnt[i * j]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] % 2 == 0)
            ans += cnt[i] / 2;
        else
            ans += cnt[i] / 2 + 1;
    }

    cout << ans << '\n';

    return 0;
}