//#7562
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-2, -1, +1, +2, +1, +2, -2, -1};
const int dx[] = {+1, +2, +2, +1, -2, -1, -1, -2};
int visited[300][300];

struct POS
{
    int y;
    int x;
    int count;
};

int main(void)
{
    int T;
    int test_case;

    cin >> T;

    for (test_case = 1; test_case <= T; test_case++)
    {
        int n, cur_r, cur_c, next_r, next_c;
        cin >> n;
        cin >> cur_r >> cur_c;
        cin >> next_r >> next_c;

        queue<POS> q;
        POS t;
        t.y = cur_r, t.x = cur_c, t.count = 0;
        visited[cur_r][cur_c] = 0;

        q.push(t);

        while (!q.empty())
        {
            POS cur = q.front();
            q.pop();

            if (cur.y == next_r && cur.x == next_c)
            {
                cout << cur.count << '\n';
                break;
            }

            for (int i = 0; i < 8; i++)
            {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
                    continue;

                POS p;
                p.y = ny, p.x = nx, p.count = cur.count + 1;
                visited[ny][nx] = 1;
                q.push(p);
            }
        }
        fill_n(visited[0], 300 * 300, 0);
    }

    return 0;
}