//https://www.acmicpc.net/problem/10797
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int day;
    int ans = 0;
    cin >> day;

    for (int i = 0; i < 5; i++)
    {
        int car;
        cin >> car;
        if (car == day)
            ans++;
    }

    cout << ans;

    return 0;
}