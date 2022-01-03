//https://www.acmicpc.net/problem/2583
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int maps[100][100];
int number = 2;
int cnt = 1;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
bool visited[100][100];
vector<int> ans;

void dfs(int y, int x);
int main(void)
{
    cin >> m >> n >> k;

    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                maps[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (!maps[y][x] && !visited[y][x])
            {
                maps[y][x] = number;
                dfs(y, x);
                number++;
                ans.push_back(cnt);
                cnt = 1;
            }
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());

    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << " ";

    cout << '\n';

    return 0;
}

void dfs(int y, int x)
{
    for (int dir = 0; dir < 4; dir++)
    {
        int nY = y + dy[dir], nX = x + dx[dir];

        if (nY < 0 || nY >= m || nX < 0 || nX >= n || visited[nY][nX])
            continue;

        if (!maps[nY][nX])
        {
            maps[nY][nX] = number;
            cnt++;
            dfs(nY, nX);
        }
    }
}