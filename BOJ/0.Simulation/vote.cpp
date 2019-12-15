//https://www.acmicpc.net/problem/10040
#include <bits/stdc++.h>
using namespace std;

int games[1000];
int money[1000];
int ans[1000];
int main(void)
{
    int n, m;
    int maxIdx = 0;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++)
        cin >> games[i];

    for (int i = 0; i < m; i++)
        cin >> money[i];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (games[j] <= money[i])
            {
                ans[j]++;
                break;
            }
        }
    }

    int M = 0;
    for (int i = 0; i < n; i++)
    {
        if (M < ans[i])
        {
            M = ans[i];
            maxIdx = i;
        }
    }

    cout << maxIdx + 1 << '\n';
    return 0;
}