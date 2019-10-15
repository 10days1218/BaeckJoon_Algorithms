//#17142
#include <bits/stdc++.h>
using namespace std;

struct POS
{
    int y;
    int x;
};

int n, m;
int maps[50][50];
int blank;
int pick[10];
int ans = INT_MAX;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
vector<POS> v;

void bfs()
{
    queue<POS> q;
    int dist[50][50];
    int time = 0;
    int cnt = 0;
    fill_n(dist[0], 50 * 50, -1);
    for (int i = 0; i < v.size(); i++)
    {
        if (pick[i])
        {
            q.push(v[i]);
            dist[v[i].y][v[i].x] = 0;
        }
    }

    while (!q.empty())
    {
        POS t = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = t.y + dy[dir], nx = t.x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (maps[ny][nx] != 1 && dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[t.y][t.x] + 1;
                if (maps[ny][nx] == 0)
                {
                    time = dist[ny][nx];
                    cnt++;
                }
                POS tmp;
                tmp.y = ny, tmp.x = nx;
                q.push(tmp);
            }
        }
    }

    if (ans > time && cnt == blank)
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
                POS t;
                t.y = i, t.x = j;
                v.push_back(t);
            }
            else if (maps[i][j] == 0)
            {
                blank++;
            }
        }
    }

    dfs(0, 0);
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << '\n';
    return 0;
}