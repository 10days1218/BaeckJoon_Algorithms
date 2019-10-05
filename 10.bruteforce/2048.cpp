//#12100
#include <bits/stdc++.h>
using namespace std;
int n;
int maps[21][21];
int answer = 0;

void shift(int type)
{
    queue<int> q;

    switch (type)
    {
    case 0:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maps[i][j])
                    q.push(maps[i][j]);
                maps[i][j] = 0;
            }

            int idx = 0;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (maps[i][idx] == 0)
                    maps[i][idx] = data;

                else if (maps[i][idx] == data)
                {
                    maps[i][idx] *= 2;
                    idx++;
                }

                else
                {
                    idx++;
                    maps[i][idx] = data;
                }
            }
        }
        break;

    case 1:
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (maps[i][j])
                    q.push(maps[i][j]);
                maps[i][j] = 0;
            }

            int idx = n - 1;

            while (!q.empty())
            {
                int data = q.front();
                q.pop();
                if (maps[i][idx] == 0)
                    maps[i][idx] = data;

                else if (maps[i][idx] == data)
                {
                    maps[i][idx] *= 2;
                    idx--;
                }

                else
                {
                    idx--;
                    maps[i][idx] = data;
                }
            }
        }

        break;

    case 2:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maps[j][i])
                    q.push(maps[j][i]);
                maps[j][i] = 0;
            }

            int idx = 0;

            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (maps[idx][i] == 0)
                    maps[idx][i] = data;

                else if (maps[idx][i] == data)
                {
                    maps[idx][i] *= 2;
                    idx++;
                }

                else
                {
                    idx++;
                    maps[idx][i] = data;
                }
            }
        }
        break;

    case 3:

        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (maps[j][i])
                    q.push(maps[j][i]);
                maps[j][i] = 0;
            }

            int idx = n - 1;

            while (!q.empty())

            {
                int data = q.front();
                q.pop();
                if (maps[idx][i] == 0)
                    maps[idx][i] = data;

                else if (maps[idx][i] == data)
                {
                    maps[idx][i] *= 2;
                    idx--;
                }

                else
                {
                    idx--;
                    maps[idx][i] = data;
                }
            }
        }
        break;
    }
}

void dfs(int cnt)
{
    if (cnt == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                answer = max(answer, maps[i][j]);
            }
        }
        return;
    }

    int copyMaps[21][21];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            copyMaps[i][j] = maps[i][j];
    }

    for (int i = 0; i < 4; i++)
    {
        shift(i);
        dfs(cnt + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                maps[i][j] = copyMaps[i][j];
        }
    }
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
        }
    }

    dfs(0);
    cout << answer << '\n';
    return 0;
}
