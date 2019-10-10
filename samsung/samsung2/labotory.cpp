//#14502
#include <bits/stdc++.h>
using namespace std;

int n, m;
int maps[9][9];
int maps_tmp[9][9] = {0};
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> virus;
int answer = -1;

void spread()
{
    int count = 0;
    int maps_spread[9][9];
    queue<pair<int, int>> q;
    q = virus;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maps_spread[i][j] = maps[i][j];
        }
    }

    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int new_y = cur_y + dy[dir];
            int new_x = cur_x + dx[dir];
            if (new_y >= 0 && new_y < n && new_x >= 0 && new_x < m && maps_spread[new_y][new_x] == 0)
            {
                maps_spread[new_y][new_x] = 2;
                q.push({new_y, new_x});
            }
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (maps_spread[y][x] == 0)
            {
                count++;
            }
        }
    }

    answer = max(answer, count);
}
void make_wall(int count)
{
    if (count == 3)
    {
        spread();
        return;
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (maps[y][x] == 0)
            {
                maps[y][x] = 1;
                make_wall(count + 1);
                maps[y][x] = 0;
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> maps[y][x];
            if (maps[y][x] == 2)
            {
                virus.push({y, x});
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         maps_tmp[i][j] = maps[i][j];
    //     }
    // }

    make_wall(0);
    cout << answer << '\n';
    return 0;
}