//#1012
#include <bits/stdc++.h>
using namespace std;

int T, M, N, K;
int maps[51][51];
int visited[51][51];
int dir_X[4] = {1, 0, -1, 0};
int dir_Y[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dir_X[i];
        int newY = y + dir_Y[i];
        if (newX >= 0 && newX < N && newY >= 0 && newY < M && !visited[newX][newY] && maps[newX][newY])
        {
            dfs(newX, newY);
        }
    }
}

int main(void)
{
    cin >> T;
    int ans = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            maps[y][x] = 1;
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (maps[j][k] == 1 && visited[j][k] == 0)
                {
                    dfs(j, k);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
        fill(maps[0], maps[0] + 51 * 51, 0);
        fill(visited[0], visited[0] + 51 * 51, 0);
        ans = 0;
    }
    return 0;
}