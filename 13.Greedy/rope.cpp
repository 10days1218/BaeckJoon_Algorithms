//#2217
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int m = v[0] * n;
    int count = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        m = max(m, v[i] * count);
        count++;
    }

    cout << m << '\n';

    return 0;
}