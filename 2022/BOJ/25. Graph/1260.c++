#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
bool visited[1001];
int graph[1001][1001];

void dfs(int x)
{
    visited[x] = true;
    cout << x << " ";

    for (int i = 1; i <= n; i++)
    {
        if (graph[x][i] == 1 && !visited[i])
            dfs(i);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 1; i <= n; i++)
        {
            if (graph[x][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        int tmp_n, tmp_v;
        cin >> tmp_n >> tmp_v;

        // 양방향
        graph[tmp_n][tmp_v] = 1;
        graph[tmp_v][tmp_n] = 1;
    }

    dfs(v);

    cout << "\n";

    // visited 초기화
    fill_n(visited, 1001, false);

    bfs(v);

    cout << "\n";

    return 0;
}