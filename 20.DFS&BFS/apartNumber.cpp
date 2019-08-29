///#2667
#include <bits/stdc++.h>
using namespace std;

int n;
int maps[26][26];
int dir_X[4] = {0, 1, 0, -1};
int dir_Y[4] = {1, 0, -1, 0};
bool visited[26][26] = {false};
vector<int> ans;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int count = 0;
    while (!q.empty())
    {
        int newX = q.front().first;
        int newY = q.front().second;
        q.pop();

        if (newX >= 0 && newX < n && newY >= 0 && newY < n && maps[newX][newY] == 1)
        {
            if (visited[newX][newY] == false)
            {
                count++;
                visited[newX][newY] = true;
                q.push(make_pair(newX, newY + 1));
                q.push(make_pair(newX + 1, newY));
                q.push(make_pair(newX, newY - 1));
                q.push(make_pair(newX - 1, newY));
            }
        }
    }

    ans.push_back(count);
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
                bfs(i, j);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    return 0;
}