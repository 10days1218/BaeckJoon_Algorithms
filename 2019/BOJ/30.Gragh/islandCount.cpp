//https://www.acmicpc.net/problem/4963
#include <bits/stdc++.h>
using namespace std;

int maps[50][50];
int visited[50][50];
int cnt;
const int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
const int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
vector<int> ans;

void bfs(int w, int h, int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});

    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 8; dir++)
        {
            int nY = ny + dy[dir];
            int nX = nx + dx[dir];
            if (nY < 0 || nY >= h || nX < 0 || nX >= w || visited[nY][nX] || !maps[nY][nX])
                continue;

            maps[nY][nX] = cnt;
            visited[nY][nX] = 1;
            q.push({nY, nX});
        }
    }
}

int main(void)
{
    while (1)
    {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        fill_n(maps[0], 50 * 50, 0);
        fill_n(visited[0], 50 * 50, 0);
        cnt = 1;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> maps[i][j];

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (maps[i][j] && !visited[i][j])
                {
                    bfs(w, h, i, j);
                    cnt++;
                }
            }
        }

        ans.push_back(cnt - 1);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';

    return 0;
}