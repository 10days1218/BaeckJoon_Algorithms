//https://www.acmicpc.net/problem/2563
#include <bits/stdc++.h>
using namespace std;

int n;
int maps[101][101];
int main(void)
{
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int k = a; k < a + 10; k++)
            for (int l = b; l < b + 10; l++)
                maps[k][l] = 1;
    }

    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            if (maps[i][j] == 1)
                ans++;

    cout << ans << '\n';
    return 0;
}