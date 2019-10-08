//#3190
#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int maps[101][101];
int snake_x[101001];
int snake_y[101001];
int tail_index;
pair<int, int> head = {1, 1};
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
char cmd[101001];
int main(void)
{
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        maps[r][c] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int t;
        char d;
        cin >> t >> d;
        cmd[t] = d;
    }

    int cur_dir = 0;
    int time = 0;
    snake_y[time] = head.first, snake_x[time] = head.second, tail_index = time;
    maps[head.first][head.second] = -1;

    while (true)
    {
        time++;
        head.first += dy[cur_dir];
        head.second += dx[cur_dir];
        //벽에 닿은 경우
        if (head.first <= 0 || head.first > n || head.second <= 0 || head.second > n || maps[head.first][head.second] == -1)
        {
            break;
        }

        snake_y[time] = head.first;
        snake_x[time] = head.second;

        if (maps[head.first][head.second] == 0)
        {
            int tail_y = snake_y[tail_index];
            int tail_x = snake_x[tail_index];
            maps[tail_y][tail_x] = 0;
            tail_index++;
        }

        maps[head.first][head.second] = -1;

        if (cmd[time] == 'D')
        {
            cur_dir = cur_dir < 3 ? cur_dir + 1 : 0;
        }
        if (cmd[time] == 'L')
        {
            cur_dir = cur_dir > 0 ? cur_dir - 1 : 3;
        }
    }

    cout << time << '\n';
    return 0;
}
