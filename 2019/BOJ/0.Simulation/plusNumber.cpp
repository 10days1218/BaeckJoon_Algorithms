//https://www.acmicpc.net/problem/1748
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    int ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i *= 10)
    {
        ans += n - i + 1;
    }

    cout << ans << '\n';
    return 0;
}