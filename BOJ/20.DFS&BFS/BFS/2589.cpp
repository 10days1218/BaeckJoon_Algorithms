//https://www.acmicpc.net/problem/2589
#include <bits/stdc++.h>
using namespace std;

struct POS
{
    int y;
    int x;
    int cost;
};

char maps[50][50];
bool visited[50][50];
int y, x;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int main(void)
{
    vector<pair<int, int>> v;
    cin >> y >> x;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> maps[i][j];

            if (maps[i][j] == 'L')
                v.push_back({i, j});
        }
    }

    queue<POS> q;
    int ans = 0;
    int dist[50][50];
    fill(&dist[0][0], &dist[0][0] + 50 * 50, 0);

    for (int i = 0; i < v.size(); i++)
    {
        q.push({v[i].first, v[i].second, 0});
        visited[v[i].first][v[i].second] = true;

        while (!q.empty())
        {
            int nY = q.front().y, nX = q.front().x, c = q.front().cost;
            q.pop();

            if (ans < c)
                ans = c;

            for (int dir = 0; dir < 4; dir++)
            {
                int nY1 = nY + dy[dir], nX1 = nX + dx[dir];
                if (visited[nY1][nX1] || maps[nY1][nX1] == 'W' || nY1 >= y || nY1 < 0 || nX1 >= x || nX1 < 0)
                    continue;

                q.push({nY1, nX1, c + 1});
                visited[nY1][nX1] = true;
            }
        }
        fill(&visited[0][0], &visited[0][0] + 50 * 50, false);
    }

    cout << ans << '\n';
    return 0;
}