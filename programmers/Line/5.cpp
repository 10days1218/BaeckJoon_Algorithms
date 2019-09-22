#include <iostream>
#include <queue>
using namespace std;
bool visit[25][25];
int n, m;

void bfs(int x, int y)
{
    queue<pair<int, pair<int, int>>> q;
    int cnt = 0, ans = 0;
    q.push({0, {0, 0}});
    if (x > n || y > m)
    {
        cout << "fail" << '\n';
        return;
    }
    while (!q.empty())
    {
        int time = q.front().first;
        int X = q.front().second.first;
        int Y = q.front().second.second;
        q.pop();
        visit[X][Y] = true;
        if (ans && time == ans && X == x && Y == y)
        {
            cnt++;
        }

        if (ans == 0 && X == x && Y == y)
        {
            ans = time;
            cnt++;
        }
        if (X + 1 < n && visit[X + 1][Y] == false)
        {
            q.push({time + 1, {X + 1, Y}});
        }

        if (Y + 1 < n && visit[X][Y + 1] == false)
        {
            q.push({time + 1, {X, Y + 1}});
        }
    }
    cout << ans << '\n'
         << cnt << '\n';
}
int main(void)
{
    int x, y;
    cin >> n >> m;
    cin >> x >> y;
    bfs(x, y);
    return 0;
}