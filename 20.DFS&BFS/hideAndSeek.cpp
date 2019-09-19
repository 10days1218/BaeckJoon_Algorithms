//#12851
#include <bits/stdc++.h>
using namespace std;
bool visit[100001] = {false};
int bfs(int n, int k)
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    int answer = 0;
    while (!q.empty())
    {
        int des = q.front().first;
        int time = q.front().second;
        q.pop();
        if (des == k)
            return time;

        if (des + 1 <= 100001 && visit[des + 1] == false)
        {
            q.push({des + 1, time + 1});
            visit[des + 1] = true;
        }
        if (des - 1 >= 0 && visit[des - 1] == false)
        {
            q.push({des - 1, time + 1});
            visit[des - 1] = true;
        }
        if (des * 2 <= 100001 && visit[des * 2] == false)
        {
            q.push({des * 2, time + 1});
            visit[des * 2] = true;
        }
    }
    return answer;
}
int main(void)
{
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k);
    return 0;
}