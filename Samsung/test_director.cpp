//#13458
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n, b, c;
    long long ans = 0;
    cin >> n;
    vector<long long> numberOfStudent(n);

    for (int i = 0; i < n; i++)
        cin >> numberOfStudent[i];

    cin >> b >> c;

    for (int i = 0; i < n; i++)
    {
        numberOfStudent[i] -= b;
        ans++;

        if (numberOfStudent[i] > 0)
        {
            numberOfStudent[i] % c == 0 ? ans += (numberOfStudent[i] / c) : ans += (numberOfStudent[i] / c + 1);
        }
    }

    cout << ans << '\n';

    return 0;
}
