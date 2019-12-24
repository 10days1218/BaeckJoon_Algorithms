//https://www.acmicpc.net/problem/1074
#include <bits/stdc++.h>
using namespace std;

// int maps[32768][32768];
int N, r, c;
int ans;

void solve(int y, int x, int n);
int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 1;

    cin >> N >> r >> c;

    for (int i = 0; i < N; i++)
        n *= 2;
    solve(0, 0, n);
    return 0;
}

void solve(int y, int x, int n)
{
    if (n == 2)
    {
        if (r < y + 2 && c < x + 2)
        {
            ans = ans + abs(y - r) * 2 + abs(x - c);
            cout << ans << '\n';
            exit(0);
        }
        else
        {
            // if (y == 0 && x == 0)
            //     ans += 3;
            // else
            ans += 4;

            //ans += 3;
        }
    }

    else
    {
        solve(y, x, n / 2);
        solve(y, x + n / 2, n / 2);
        solve(y + n / 2, x, n / 2);
        solve(y + n / 2, x + n / 2, n / 2);
        return;
    }
}
