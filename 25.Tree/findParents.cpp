//#11725
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;
int n;
vector<int> tree[MAX];
int parent[MAX];
bool visit[MAX];
void dfs(int node)
{
    visit[node] = true;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i];
        if (!visit[next])
        {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int p, c;
        cin >> p >> c;
        tree[p].push_back(c);
        tree[c].push_back(p);
    }

    dfs(1);
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';

    return 0;
}