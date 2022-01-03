//#14503
#include <bits/stdc++.h>
using namespace std;

int n, m;
int r, c, d;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int maps[51][51];
int main(void)
{
    cin >> n >> m;
    cin >> r >> c >> d;
    int answer = 0;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> maps[y][x];
        }
    }

    int cur_y = r, cur_x = c, cur_dir = d;

    while (1)
    {
        bool check = false;
        if (maps[cur_y][cur_x] == 0)
        {
            answer++;
            maps[cur_y][cur_x] = -1;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int new_dir = cur_dir == 0 ? 3 : cur_dir - 1;
            int new_y = cur_y + dy[new_dir], new_x = cur_x + dx[new_dir];
            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m)
            {
                continue;
            }

            if (maps[new_y][new_x] == 0)
            {
                cur_y = new_y, cur_x = new_x;
                cur_dir = new_dir;
                check = true;
                break;
            }
            else
                cur_dir = new_dir;
        }

        if (!check)
        {
            int new_y = cur_y + (-1) * dy[cur_dir], new_x = cur_x + (-1) * dx[cur_dir];
            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m)
            {
                continue;
            }

            if (maps[new_y][new_x] != 1)
            {
                cur_y = new_y, cur_x = new_x;
            }
            else
            {
                break;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}