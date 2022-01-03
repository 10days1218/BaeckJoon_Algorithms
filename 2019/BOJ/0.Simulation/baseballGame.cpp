//https://www.acmicpc.net/problem/1159
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    map<char, int> m;
    string ans;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (m.find(tmp[0]) == m.end())
            m[tmp[0]] = 1;
        else
        {
            m.find(tmp[0])->second++;
        }
    }

    map<char, int>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second >= 5)
            ans += iter->first;
    }

    if (ans.size() == 0)
        cout << "PREDAJA\n";

    else
        cout << ans << '\n';
    return 0;
}