//#10816
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)

        cin >> v[i];

    sort(v.begin(), v.end());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)

    {
        int num;
        cin >> num;
        cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
    }

    cout << "\n";

    return 0;
}