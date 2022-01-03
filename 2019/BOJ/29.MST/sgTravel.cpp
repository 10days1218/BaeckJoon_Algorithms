//https://www.acmicpc.net/problem/9372
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int e, v;
            cin >> e >> v;
        }

        cout << n - 1 << '\n';
    }

    return 0;
}