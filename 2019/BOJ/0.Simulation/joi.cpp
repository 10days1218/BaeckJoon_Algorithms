//https://www.acmicpc.net/problem/5585
#include <bits/stdc++.h>
using namespace std;

int coin[] = {500, 100, 50, 10, 5, 1};
int main(void)
{
    int money;
    int ans = 0;
    cin >> money;
    money = 1000 - money;

    for (int i = 0; i < 6; i++)
    {
        ans += money / coin[i];
        money %= coin[i];
    }

    cout << ans << '\n';

    return 0;
}