//#https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>
using namespace std;

// vector<int> g[100];
int matrix[100][100];
int ans[100][100];
bool visited[100];
int n;

void dfs(int start, int next);
int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < n; i++)
    {
        fill(visited, visited + 100, false);
        dfs(i, i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

void dfs(int start, int next)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[next][i] && !visited[i])
        {
            visited[i] = true;
            ans[start][i] = 1;
            dfs(start, i);
        }
    }
}