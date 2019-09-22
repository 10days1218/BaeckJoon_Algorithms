#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, t;
    int total = 0;
    int time[501];
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> time[i];

    for (int i = 0; i < n; i++)
    {
        total += time[i];
        if (total > t)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    return 0;
}