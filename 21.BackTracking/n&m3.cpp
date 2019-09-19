//#15651
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;
// bool visited[8];
void dfs(int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        ans.push_back(i);
        dfs(count + 1);
        ans.pop_back();
    }
}
int main(void)
{
    cin >> n >> m;
    dfs(0);
    return 0;
}