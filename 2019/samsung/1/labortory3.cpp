//#17142
#include <bits/stdc++.h>
using namespace std;

int n, m;
int maps[51][51];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> virus;
int answer = INT_MAX;
int cnt = 0;
bool visited[10];

void spread()
{
    int time = 0;
    int tmp_cnt = cnt;
    int maps_tmp[51][51];
    fill_n(maps_tmp[0], 51 * 51, -1);

    queue<pair<int, int>> q;

    for (int i = 0; i < virus.size(); i++)
    {
        if (visited[i])
        {
            q.push({virus[i].first, virus[i].second});
            maps_tmp[virus[i].first][virus[i].second] = 0;
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
            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= n)
                continue;

            if (maps[new_y][new_x] != 1 && maps_tmp[new_y][new_x] == -1)
            {
                maps_tmp[new_y][new_x] = maps_tmp[cur_y][cur_x] + 1;
                if (maps[new_y][new_x] == 0)
                {
                    time = maps_tmp[new_y][new_x];
                    tmp_cnt--;
                }
                q.push({new_y, new_x});
            }
        }
    }

    if (tmp_cnt == 0)
    {
        answer = min(answer, time);
    }
}

void dfs(int cnt, int idx)
{
    if (cnt == m)
    {
        spread();
        return;
    }

    for (int i = idx; i < virus.size(); i++)
    {
        visited[i] = true;
        dfs(cnt + 1, i + 1);
        visited[i] = false;
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
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 2)
            {
                virus.push_back({i, j});
            }
            if (maps[i][j] == 0)
            {
                cnt++;
            }
        }
    }

    dfs(0, 0);
    answer = answer == INT_MAX ? -1 : answer;
    cout << answer << '\n';
    return 0;
}