//#16234
#include <bits/stdc++.h>
using namespace std;

struct POS
{
    int Y;
    int X;
};

int n, l, r;
int people[50][50];
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int main(void)
{
    cin >> n >> l >> r;
    int cnt = 0;
    int ans = 0;
    bool flag = true;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> people[y][x];
        }
    }
    while (flag)
    {
        int line[50][50] = {};
        fill_n(line[0], 50 * 50, 0);
        flag = false;
        queue<POS> q;
        queue<POS> country;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (line[y][x])
                    continue;

                int total = 0;
                POS t;
                t.Y = y, t.X = x;
                q.push(t);
                country.push(t);
                line[y][x] = 1;
                total += people[y][x];

                while (!q.empty())
                {
                    POS tmp = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int ny = tmp.Y + dy[dir], nx = tmp.X + dx[dir];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n || line[ny][nx])
                            continue;

                        int value = abs(people[tmp.Y][tmp.X] - people[ny][nx]);
                        if (value >= l && value <= r)
                        {
                            POS temp;
                            temp.Y = ny, temp.X = nx;
                            total += people[ny][nx];
                            line[ny][nx] = 1;
                            q.push(temp);
                            country.push(temp);
                            flag = true;
                        }
                    }
                }

                int ret = total / country.size();
                while (!country.empty())
                {
                    int i = country.front().Y, j = country.front().X;
                    country.pop();
                    people[i][j] = ret;
                }
            }
        }
        ans++;
    }

    cout << ans - 1 << '\n';
    return 0;
}