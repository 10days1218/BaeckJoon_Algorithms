//#12851
#include <bits/stdc++.h>
using namespace std;
bool visit[100001] = {false};
void bfs(int n, int k)
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    int cnt = 0, ans = 0;
    while (!q.empty())
    {
        int des = q.front().first;
        int time = q.front().second;
        q.pop();
        visit[des] = true;
        if (ans && time == ans && des == k)
        {
            cnt++;
        }

        if (ans == 0 && des == k)
        {
            ans = time;
            cnt++;
        }

        if (des + 1 <= 100001 && visit[des + 1] == false)
        {
            q.push({des + 1, time + 1});
        }
        if (des - 1 >= 0 && visit[des - 1] == false)
        {
            q.push({des - 1, time + 1});
        }
        if (des * 2 <= 100001 && visit[des * 2] == false)
        {
            q.push({des * 2, time + 1});
        }
    }
    cout << ans << '\n'
         << cnt << '\n';
}
int main(void)
{
    int n, k;
    cin >> n >> k;
    bfs(n, k);
    return 0;
}