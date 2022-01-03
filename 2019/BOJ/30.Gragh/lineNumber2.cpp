//#16947
//https://www.acmicpc.net/problem/16947
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[3001];
int check[3001]; //노드 부모 정보
int dist[3001];  //거리 정보 배열

int checkCycle(int x, int p)
{
    if (check[x] == 1)
    {
        return x;
    }

    check[x] = 1;

    for (int i = 0; i < g[x].size(); i++)
    {
        int y = g[x][i];
        if (y == p)
            continue;
        int ret = checkCycle(y, x);
        if (ret == -2)
            return -2;
        if (ret >= 0)
        {
            check[x] = 2; // 사이클
            if (ret == x)
                return -2; // 시작점
            else
                return ret; // 사이클이면서 시작점이 아닐 때
        }
    }

    return -1;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int v, e;
        cin >> v >> e;
        g[v].push_back(e);
        g[e].push_back(v);
    }

    checkCycle(1, -1);
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (check[i] == 2)
        {
            dist[i] = 0;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < g[x].size(); i++)
        {
            int y = g[x][i];
            if (check[y] == 2)
                continue;
            check[y] = 2;
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}