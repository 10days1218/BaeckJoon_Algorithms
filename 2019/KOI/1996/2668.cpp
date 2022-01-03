//https://www.acmicpc.net/problem/2668
#include <bits/stdc++.h>
using namespace std;

int n;
int number[101];
bool visited[101];
vector<int> v;
void dfs(int start, int current);
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> number[i];

    for (int i = 1; i <= n; i++)
    {
        fill(visited, visited + 101, 0);
        dfs(i, i);
    }

    cout << (int)v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }

    return 0;
}

void dfs(int start, int current)
{
    if (visited[current])
    {
        if (current == start)
            v.push_back(start);
    }
    else
    {
        visited[current] = true;
        dfs(start, number[current]);
    }
}
