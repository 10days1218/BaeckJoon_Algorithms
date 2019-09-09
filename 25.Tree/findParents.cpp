//#11725
#include <bits/stdc++h>
using namespace std;

const int max = 1001;
bool visit[max];
vector<int> adj[max];
queue<int> Q;

void DFS(int x)
{
    visit[x] = true;
    cout << x << ' ';

    for(int i )
}

void BFS(int sx)
{
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 0; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    return 0;
}