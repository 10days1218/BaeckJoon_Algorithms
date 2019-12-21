//https://www.acmicpc.net/problem/2468
#include <bits/stdc++.h>
using namespace std;

int n;
int maps[100][100];
int mapsCopy[100][100];
int visited[100][100];

int solve(int h);
void bfs(int y, int x);
int main(void)
{
    int m = 0;
    int ret = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
            if (m < maps[i][j])
                m = maps[i][j];
        }
    }

    // if (m == 1)
    //     ret = 0;

    //else
    //{
    for (int i = 0; i <= m; i++)
        ret = max(ret, solve(i));
    //}

    cout << ret << '\n';

    return 0;
}

int solve(int h)
{
    int cnt = 0;
    copy(&maps[0][0], &maps[0][0] + 100 * 100, &mapsCopy[0][0]);
    fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mapsCopy[i][j] <= h)
            {
                mapsCopy[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mapsCopy[i][j] && !visited[i][j])
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first < 0 || p.first >= n || p.second < 0 || p.second >= n || visited[p.first][p.second] || !mapsCopy[p.first][p.second])
            continue;

        visited[p.first][p.second] = true;
        q.push({p.first + 1, p.second});
        q.push({p.first, p.second + 1});
        q.push({p.first - 1, p.second});
        q.push({p.first, p.second - 1});
    }
}