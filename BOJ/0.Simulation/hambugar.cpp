//https://www.acmicpc.net/problem/5543
#include <bits/stdc++.h>
using namespace std;

int bugar[3];
int drink[2];
int main(void)
{
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
        cin >> bugar[i];

    for (int i = 0; i < 2; i++)
        cin >> drink[i];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans = min(ans, bugar[i] + drink[j] - 50);
        }
    }

    cout << ans << '\n';

    return 0;
}