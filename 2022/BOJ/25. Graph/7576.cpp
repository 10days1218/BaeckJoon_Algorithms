//#7576
#include <bits/stdc++.h>
using namespace std;

int m, n;
int board[1001][1001];
queue<pair<int, int>> q;
int visited[1001][1001] = {-1};
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int bfs()
{
    int answer = -2;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int X = x + dir[i][0];
            int Y = y + dir[i][1];
            if (X >= 0 && X < n && Y >= 0 && Y < m && board[X][Y] == 0)
            {
                board[X][Y] = 1;
                q.push(make_pair(X, Y));
                visited[X][Y] = visited[x][y] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            answer = max(answer, visited[i][j]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
            {
                answer = -1;
            }
    }
    return answer;
}
int main(void)
{
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                q.push(make_pair(i, j));
                visited[i][j] = 0;
            }
        }
    }

    cout << bfs() << "\n";

    return 0;
}