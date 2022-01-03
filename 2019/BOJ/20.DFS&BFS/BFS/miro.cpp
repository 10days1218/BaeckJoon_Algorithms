//#2178
#include <bits/stdc++.h>
using namespace std;

int n, m;
string maps[101];
bool visited[101][101];
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};

int bfs(int x, int y, int count)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(x, y), 1));
    visited[x][y] = true;
    while (!q.empty())
    {
        int X = q.front().first.first;
        int Y = q.front().first.second;
        int count = q.front().second;
        q.pop();
        if (X == n - 1 && Y == m - 1)
            return count;
        for (int i = 0; i < 4; i++)
        {
            int newX = X + dir_x[i];
            int newY = Y + dir_y[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && maps[newX][newY] == '1')
            {
                q.push(make_pair(make_pair(newX, newY), count + 1));
                visited[newX][newY] = true;
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> maps[i];
    }
    cout << bfs(0, 0, 1) << '\n';

    return 0;
}