//#15650
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
bool visited[9];

void dfs(int count, int idx)
{
    if (count == m)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = idx; i <= n; i++)
    {
        if (!visited[i])
        {
            v.push_back(i);
            visited[i] = true;
            dfs(count + 1, i);
            visited[i] = false;
            v.pop_back();
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dfs(0, 1);

    return 0;
}