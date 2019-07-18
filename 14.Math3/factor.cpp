//#1037
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    cout << v[0] * v[n - 1] << '\n';

    return 0;
}