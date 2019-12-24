//https://www.acmicpc.net/problem/10026
#include <bits/stdc++.h>
using namespace std;

int n;
char maps[100][100];
// char maps2[100][100];
int visited[100][100];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct POS
{
    int y;
    int x;
};

void bfs1(int y, int x, char color); //적색색약x
void bfs2(int y, int x, char color); //적색색약o
int main(void)
{
    int ans1 = 0, ans2 = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs1(i, j, maps[i][j]);
                ans1++;
            }
        }
    }

    fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maps[i][j] == 'G')
                maps[i][j] = 'R';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs2(i, j, maps[i][j]);
                ans2++;
            }
        }
    }

    cout << ans1 << " " << ans2 << '\n';
    return 0;
}

void bfs1(int y, int x, char color)
{
    int cnt = 0;
    queue<POS> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (!q.empty())
    {
        POS f = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nY = f.y + dy[dir], nX = f.x + dx[dir];
            if (nY < 0 || nY >= n || nX < 0 || nX >= n || visited[nY][nX] || maps[nY][nX] != color)
                continue;

            visited[nY][nX] = 1;
            q.push({nY, nX});
        }
    }
}

void bfs2(int y, int x, char color)
{

    int cnt = 0;
    queue<POS> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (!q.empty())
    {
        POS f = q.front();
        q.pop();
        visited[f.y][f.x] = 1;

        for (int dir = 0; dir < 4; dir++)
        {
            int nY = f.y + dy[dir], nX = f.x + dx[dir];
            if (nY < 0 || nY >= n || nX < 0 || nX >= n || visited[nY][nX] || maps[nY][nX] != color)
                continue;

            visited[nY][nX] = 1;
            q.push({nY, nX});
        }
    }
}