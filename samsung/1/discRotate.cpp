//#17822
#include <bits/stdc++.h>
using namespace std;

struct CMD
{
    int num;
    int dir;
    int cnt;
};

struct POS
{
    int y;
    int x;
};

CMD cmd[50];
int visited[51][51];
int disc[51][51];
int n, m, t;

void print()
{
    cout << '\n';

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << disc[i][j] << " ";
        }
        cout << '\n';
    }
}

void rotate(int num, int dir, int cnt)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            if (i % num == 0)
            {
                if (dir == 0)
                {
                    int tmp = disc[i][m - 1];
                    for (int k = m - 2; k >= 0; k--)
                    {
                        disc[i][k + 1] = disc[i][k];
                    }
                    disc[i][0] = tmp;
                }

                else
                {
                    int tmp = disc[i][0];
                    for (int k = 0; k < m - 1; k++)
                    {
                        disc[i][k] = disc[i][k + 1];
                    }
                    disc[i][m - 1] = tmp;
                }
            }
        }
    }
}

int delDisc()
{
    int count = 0;
    fill_n(visited[0], 51 * 51, 0);
    queue<POS> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int up = j - 1, down = j + 1;
            if (up >= 1 && up <= n && disc[up][i] == disc[j][i] && disc[j][i] != 0)
            {
                if (!visited[up][i])
                {
                    POS t;
                    t.y = up, t.x = i;
                    visited[up][i] = 1;
                    q.push(t);
                }
                if (!visited[j][i])
                {
                    POS t;
                    t.y = j, t.x = i;
                    visited[j][i] = 1;
                    q.push(t);
                }
            }

            if (down >= 1 && down <= n && disc[down][i] == disc[j][i] && disc[j][i] != 0)
            {
                if (!visited[down][i])
                {
                    POS t;
                    t.y = down, t.x = i;
                    visited[down][i] = 1;
                    q.push(t);
                }
                if (!visited[j][i])
                {
                    POS t;
                    t.y = j, t.x = i;
                    visited[j][i] = 1;
                    q.push(t);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int left = j - 1 < 0 ? m - 1 : j - 1;
            int right = j + 1 >= m ? 0 : j + 1;

            if (disc[i][left] == disc[i][j] && disc[i][j] != 0)
            {
                if (!visited[i][left])
                {
                    POS t;
                    t.y = i, t.x = left;
                    visited[i][left] = 1;
                    q.push(t);
                }

                if (!visited[i][j])
                {
                    POS t;
                    t.y = i, t.x = j;
                    visited[i][j] = 1;
                    q.push(t);
                }
            }

            if (disc[i][right] == disc[i][j] && disc[i][j] != 0)
            {
                if (!visited[i][right])
                {
                    POS t;
                    t.y = i, t.x = right;
                    visited[i][right] = 1;
                    q.push(t);
                }

                if (!visited[i][j])
                {
                    POS t;
                    t.y = i, t.x = j;
                    visited[i][j] = 1;
                    q.push(t);
                }
            }
        }
    }

    count = q.size();

    while (!q.empty())
    {
        POS cur = q.front();
        q.pop();
        disc[cur.y][cur.x] = 0;
    }

    return count;
}

void makeValue()
{
    double cnt = 0;
    double total;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (disc[i][j] != 0)
            {
                total += disc[i][j];
                cnt++;
            }
        }
    }

    if (cnt > 0)
    {
        double aver = total / cnt;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (disc[i][j] > aver && disc[i][j] != 0)
                {
                    disc[i][j] -= 1;
                }

                else if (disc[i][j] < aver && disc[i][j] != 0)
                {
                    disc[i][j] += 1;
                }
            }
        }
    }
}

int main(void)
{
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> disc[i][j];
        }
    }

    for (int i = 0; i < t; i++)
    {
        cin >> cmd[i].num >> cmd[i].dir >> cmd[i].cnt;
    }

    for (int i = 0; i < t; i++)
    {
        int dir = cmd[i].dir;
        int num = cmd[i].num;
        int cnt = cmd[i].cnt;

        rotate(num, dir, cnt);

        int count = delDisc();

        if (count == 0)
        {
            makeValue();
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (disc[i][j] != 0)
            {
                ans += disc[i][j];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}