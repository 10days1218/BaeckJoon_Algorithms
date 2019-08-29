///#2667
#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int maps[26][26];
int dir_X[4] = {0, 1, 0, -1};
int dir_Y[4] = {1, 0, -1, 0};
bool visited[26][26] = {false};
vector<int> ans;

void dfs(int x, int y)
{
    visited[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dir_X[i];
        int newY = y + dir_Y[i];
        if (newX >= 0 && newX < n && newY >= 0 && newY < n && visited[newX][newY] == false && maps[newX][newY])
        {
            dfs(newX, newY);
        }
    }
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            maps[i][j] = tmp[j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maps[i][j] == 1 && visited[i][j] == false)
            {
                dfs(i, j);
                ans.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    return 0;
}