//17141
#include <bits/stdc++.h>
using namespace std;

int n, m;
int maps[50][50];
vector<pair<int, int> > v;
int blank;
int ans = INT_MAX;
bool pick[10];
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

void bfs()
{
    int dist[50][50];
    int time = 0;
    int cnt = 0;
    queue<pair<int, int> > q;

    fill_n(dist[0], 50 * 50, -1);

    for (int i = 0; i < v.size(); i++)
    {
        if (pick[i])
        {
            q.push(v[i]);
            dist[v[i].first][v[i].second] = 0;
        }
    }

    while (!q.empty())
    {
        int cur_y = q.front().first, cur_x = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur_y + dy[dir], nx = cur_x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (maps[ny][nx] != 1 && dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[cur_y][cur_x] + 1;
                time = dist[ny][nx];
                cnt++;
                q.push(make_pair(ny, nx));
            }
        }
    }

    if (ans > time && cnt == blank + v.size() - m)
    {
        ans = time;
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
        if (!pick[i])
        {
            pick[i] = true;
            dfs(cnt + 1, i + 1);
            pick[i] = false;
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
                v.push_back(make_pair(i, j));
            }
            if (maps[i][j] == 0)
            {
                blank++;
            }
        }
    }

    dfs(0, 0);
    if (ans == INT_MAX)
    {
        ans = -1;
    }
    cout << ans << '\n';
    return 0;
}