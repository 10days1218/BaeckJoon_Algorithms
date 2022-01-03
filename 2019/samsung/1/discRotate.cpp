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

CMD cmd[51];
int visited[51][51];
int disc[51][51];
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
bool flag = false;
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

void delDisc(int y, int x, int num)
{
    int visited[51][51];
    fill_n(visited[0], 51 * 51, 0);
    queue<POS> q;
    POS tmp;
    tmp.y = y, tmp.x = x;
    q.push(tmp);

    while (!q.empty())
    {
        POS p = q.front();
        q.pop();
    }
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (disc[i][j] != 0)
            {
                delDisc(i, j, disc[i][j]);
            }
        }
    }

    if (!flag)
    {
        makeValue();
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
            ans += disc[i][j];
        }
    }

    cout << ans << '\n';
    return 0;
}