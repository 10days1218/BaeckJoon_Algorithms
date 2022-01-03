//#1931
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 1;
    int check = 0;
    vector<pair<int, int>> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back(pair<int, int>(tmp2, tmp1));
    }

    sort(v.begin(), v.end());

    check = v[0].first;

    for (int i = 1; i < n; i++)
    {
        //cout << "!" << '\n';
        if (v[i].second >= check)
        {
            check = v[i].first;
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}