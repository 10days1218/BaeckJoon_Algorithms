//#15649
#include <bits/stdc++.h>
using namespace std;
#define MAX 9

int n, m;
vector<int> v;
bool visited[MAX];

void dfs(int count)
{
    if (count == m)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            v.push_back(i);
            visited[i] = true;
            dfs(count + 1);
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

    dfs(0);
    return 0;
}