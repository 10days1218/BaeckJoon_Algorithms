//#12851
#include <bits/stdc++.h>
using namespace std;
bool visit[100001];
int bfs(int n, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, n});
    visit[n] = true;

    while (!q.empty())
    {
        int time = q.top().first;
        int des = q.top().second;
        q.pop();

        if (des == k)
            return time;

        if (des * 2 <= 100001 && visit[des * 2] == false)
        {
            q.push({time, des * 2});
            visit[des * 2] = true;
        }
        if (des + 1 <= 100001 && visit[des + 1] == false)
        {
            q.push({time + 1, des + 1});
            visit[des + 1] = true;
        }
        if (des - 1 >= 0 && visit[des - 1] == false)
        {
            q.push({time + 1, des - 1});
            visit[des - 1] = true;
        }
    }
}
int main(void)
{
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << '\n';
    return 0;
}