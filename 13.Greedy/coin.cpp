#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, k, count = 0;
    int i = 0;
    cin >> n >> k;
    vector<int> v(n, 0);
    i = n - 1;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    while (i >= 0)
    {
        if (k / v[i] == 0)
            i--;
        else
        {
            count += k / v[i];
            k = k - (k / v[i] * v[i]);
        }

        if (k == 0)
            break;
    }

    cout << count << '\n';

    return 0;
}