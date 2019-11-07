//https://www.acmicpc.net/problem/1764
#include <bits/stdc++.h>
using namespace std;

set<string> h;
vector<string> ans;
int main(void)
{
    int n, m;
    string tmp;
    int cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        h.insert(tmp);
    }

    set<string>::iterator i;
    for (int j = 0; j < m; j++)
    {
        cin >> tmp;
        i = h.find(tmp);
        if (i != h.end())
            ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';

    return 0;
}