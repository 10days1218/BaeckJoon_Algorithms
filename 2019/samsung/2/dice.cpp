//#14499
#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, k;
int cmd[1000];
int maps[20][20];
int dice[7];
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int main(void)
{
    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        cin >> cmd[i];
        cmd[i]--;
    }

    for (int i = 0; i < k; i++)
    {
        int d = cmd[i];
        int ny = y + dy[d], nx = x + dx[d];
        //cout << ny << " " << nx << " " << '\n';

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (cmd[i] == 0)
        {
            dice[0] = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = dice[0];
        }

        if (cmd[i] == 1)
        {
            dice[0] = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = dice[0];
        }

        if (cmd[i] == 2)
        {
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = dice[0];
        }

        if (cmd[i] == 3)
        {
            dice[0] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = dice[0];
        }

        if (maps[ny][nx] == 0)
        {
            maps[ny][nx] = dice[6];
        }

        else
        {
            dice[6] = maps[ny][nx];
            maps[ny][nx] = 0;
        }
        y = ny, x = nx;
        cout << dice[1] << '\n';
    }

    return 0;
}