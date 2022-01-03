//https://www.acmicpc.net/problem/5032
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int e, f, c;
    int ans = 0;
    int tmp = 0;
    cin >> e >> f >> c;

    ans = (e + f) / c;
    tmp = ans + (e + f) % c;

    while (tmp >= c)
    {
        ans += tmp / c;
        tmp = tmp % c + tmp / c;
    }

    cout << ans << '\n';
    return 0;
}