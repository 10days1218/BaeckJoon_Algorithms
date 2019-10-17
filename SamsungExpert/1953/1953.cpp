//#1953 탈주범 검거
#include <bits/stdc++.h>
using namespace std;
int maps[50][50];
int visited[50][50];
const int dy[] = {1, -1, 0, 0}; // 하 상 우 좌
const int dx[] = {0, 0, 1, -1};

struct POS
{
    int y;
    int x;
    int time;
};

bool check(int dir, int y, int x)
{
    if (dir == 0)
    {
        if (maps[y][x] == 1 || maps[y][x] == 2 || maps[y][x] == 4 || maps[y][x] == 7)
        {
            return true;
        }
    }

    if (dir == 1)
    {
        if (maps[y][x] == 1 || maps[y][x] == 2 || maps[y][x] == 5 || maps[y][x] == 6)
        {
            return true;
        }
    }

    if (dir == 2)
    {
        if (maps[y][x] == 1 || maps[y][x] == 3 || maps[y][x] == 6 || maps[y][x] == 7)
        {
            return true;
        }
    }

    if (dir == 3)
    {
        if (maps[y][x] == 1 || maps[y][x] == 3 || maps[y][x] == 4 || maps[y][x] == 5)
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    int T, n, m, r, c, l;
    int ans = 0;
    queue<POS> q;

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> n >> m >> r >> c >> l;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> maps[i][j];
            }
        }

        POS t;
        t.y = r, t.x = c, t.time = 1;
        visited[r][c] = true;
        q.push(t);

        while (!q.empty())
        {
            POS p = q.front();
            q.pop();
            ans++;
            if (maps[p.y][p.x] == 1)
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = p.y + dy[dir], nx = p.x + dx[dir];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || p.time + 1 > l)
                        continue;

                    if (check(dir, ny, nx))
                    {
                        POS tmp;
                        tmp.y = ny, tmp.x = nx, tmp.time = p.time + 1;
                        q.push(tmp);
                        visited[ny][nx] = true;
                    }
                }
            }
            if (maps[p.y][p.x] == 2)
            {
                for (int dir = 0; dir < 2; dir++)
                {
                    int ny = p.y + dy[dir], nx = p.x + dx[dir];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || p.time + 1 > l)
                        continue;
                    if (check(dir, ny, nx))
                    {
                        POS tmp;
                        tmp.y = ny, tmp.x = nx, tmp.time = p.time + 1;
                        q.push(tmp);
                        visited[ny][nx] = true;
                    }
                }
            }

            if (maps[p.y][p.x] == 3)
            {
                for (int dir = 2; dir < 4; dir++)
                {
                    int ny = p.y + dy[dir], nx = p.x + dx[dir];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || p.time + 1 > l)
                        continue;

                    if (check(dir, ny, nx))
                    {
                        POS tmp;
                        tmp.y = ny, tmp.x = nx, tmp.time = p.time + 1;
                        q.push(tmp);
                        visited[ny][nx] = true;
                    }
                }
            }

            if (maps[p.y][p.x] == 4)
            {
                for (int dir = 1; dir < 3; dir++)
                {
                    int ny = p.y + dy[dir], nx = p.x + dx[dir];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || p.time + 1 > l)
                        continue;

                    if (check(dir, ny, nx))
                    {
                        POS tmp;
                        tmp.y = ny, tmp.x = nx, tmp.time = p.time + 1;
                        q.push(tmp);
                        visited[ny][nx] = true;
                    }
                }
            }

            if (maps[p.y][p.x] == 5)
            {
                for (int dir = 0; dir < 3; dir += 2)
                {
                    int ny = p.y + dy[dir], nx = p.x + dx[dir];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || p.time + 1 > l)
                        continue;
                    if (check(dir, ny, nx))
                    {
                        POS tmp;
                        tmp.y = ny, tmp.x = nx, tmp.time = p.time + 1;
                        q.push(tmp);
                        visited[ny][nx] = true;
                    }
                }
            }

            if (maps[p.y][p.x] == 6)
            {
                for (int dir = 0; dir < 4; dir += 3)
                {
                    int ny = p.y + dy[dir], nx = p.x + dx[dir];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || p.time + 1 > l)
                        continue;
                    if (check(dir, ny, nx))
                    {
                        POS tmp;
                        tmp.y = ny, tmp.x = nx, tmp.time = p.time + 1;
                        q.push(tmp);
                        visited[ny][nx] = true;
                    }
                }
            }

            if (maps[p.y][p.x] == 7)
            {
                for (int dir = 1; dir < 4; dir += 2)
                {
                    int ny = p.y + dy[dir], nx = p.x + dx[dir];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || p.time + 1 > l)
                        continue;
                    if (check(dir, ny, nx))
                    {
                        POS tmp;
                        tmp.y = ny, tmp.x = nx, tmp.time = p.time + 1;
                        q.push(tmp);
                        visited[ny][nx] = true;
                    }
                }
            }
        }
        cout << "#" << test_case << " " << ans << '\n';
        fill_n(maps[0], 50 * 50, 0);
        fill_n(visited[0], 50 * 50, false);
        ans = 0;
    }
    return 0;
}