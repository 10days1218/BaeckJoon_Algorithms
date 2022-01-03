//#17141
#include <bits/stdc++.h>
using namespace std;

int n, m;
int maps[50][50];
vector<pair<int, int>> v;
bool check[10];
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int answer = INT_MAX;
int infection = 0;
queue<pair<int, int>> q;
void bfs()
{
    int time = 0;
    int blank = infection + v.size() - m;
    int dist[50][50];
    fill_n(dist[0], 50 * 50, -1);

    for (int i = 0; i < v.size(); i++)
    {
        if (check[i])
        {
            q.push(v[i]);
            dist[v[i].first][v[i].second] = 0;
        }
    }

    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        time = dist[cur_y][cur_x];
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur_y + dy[dir], nx = cur_x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (maps[ny][nx] != 1 && dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[cur_y][cur_x] + 1;
                blank--;
                q.push({ny, nx});
            }
        }
    }

    if (blank == 0 && answer > time)
    {
        answer = time;
    }
}

void dfs(int cnt, int idx)
{
    if (cnt == m)
    {
        bfs();
        return;
    }

    for (int i = idx; i < v.size(); i++)
    {
        if (!check[i])
        {
            check[i] = true;
            dfs(cnt + 1, idx + 1);
            check[i] = false;
        }
    }
}
int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 2)
            {
                v.push_back({i, j});
            }
            if (maps[i][j] == 0)
            {
                infection++;
            }
        }
    }

    dfs(0, 0);
    if (answer == INT_MAX)
    {
        answer = -1;
    }
    cout << answer << '\n';
    return 0;
}
