//#1920
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cin >> m;
    vector<int> w(m);

    for (int i = 0; i < m; i++)
        cin >> w[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++)
        cout << binary_search(v.begin(), v.end(), w[i]) << '\n';

    return 0;
}