//#15652
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void dfs(int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
            cout << v[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (v.empty() || v.back() <= i)
        {
            v.push_back(i);
            dfs(count + 1);
            v.pop_back();
        }
    }
}
int main(void)
{
    cin >> n >> m;
    dfs(0);
    return 0;
}