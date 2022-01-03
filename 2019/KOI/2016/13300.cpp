//https://www.acmicpc.net/problem/13300
#include <bits/stdc++.h>
using namespace std;

int student[6][2];

int main(void)
{
    int n, k;
    int ans = 0;
    cin >> n >> k;

    while (n--)
    {
        int s, y;
        cin >> s >> y;
        student[y - 1][s] += 1;
    }

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 2; j++)
            ans += student[i][j] % k == 0 ? student[i][j] / k : student[i][j] / k + 1;

    cout << ans << '\n';
    return 0;
}