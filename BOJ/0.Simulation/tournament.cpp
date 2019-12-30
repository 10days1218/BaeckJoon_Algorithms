//https://www.acmicpc.net/problem/1057
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t, n, m;
    cin >> t >> n >> m;
    int cnt = 1;
    int ans = -1;

    while (n >= 1 && m >= 1)
    {

        if (n < m && n % 2 == 1 && n + 1 == m)
        {
            ans = cnt;
            break;
        }
        else if (n > m && m % 2 == 1 && m + 1 == n)
        {
            ans = cnt;
            break;
        }

        n = n % 2 == 0 ? n / 2 : n / 2 + 1;
        m = m % 2 == 0 ? m / 2 : m / 2 + 1;
        cnt++;
    }

    cout << ans << '\n';

    return 0;
}