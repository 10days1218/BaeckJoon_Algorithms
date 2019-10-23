//#16236
#include <bits/stdc++.h>
using namespace std;

struct SHARK
{
    int y;
    int x;
    int time;
};
int n;
int maps[20][20];
int shark_size, shark_eat;
SHARK shark;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 9)
            {
                shark.y = i, shark.x = j, shark.time = 0;
                shark_size = 2, shark_eat = 0;
                maps[i][j] = 0;
            }
        }
    }

    bool is_update = true;
    while (is_update)
    {
        is_update = false;

        bool visited[20][20];
        fill_n(visited[0], 20 * 20, false);
        queue<SHARK> q;
        visited[shark.y][shark.x] = true;
        q.push(shark);

        SHARK candi;
        candi.y = 20, candi.time = -1;
        while (!q.empty())
        {
            SHARK cur = q.front();
            q.pop();

            //cout << cur.y << " " << cur.x << " " << cur.time << '\n';

            if (candi.time != -1 && candi.time < cur.time) // 가장 가까운 물고기가 없다
                break;

            if (maps[cur.y][cur.x] < shark_size && maps[cur.y][cur.x] != 0)
            {
                is_update = true;
                if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x))
                {
                    candi = cur;
                }
            }

            for (int dir = 0; dir < 4; dir++)
            {
                SHARK next;
                next.y = cur.y + dy[dir];
                next.x = cur.x + dx[dir];
                next.time = cur.time + 1;

                if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
                    continue;

                if (visited[next.y][next.x] == false && shark_size >= maps[next.y][next.x])
                {
                    visited[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }

        if (is_update)
        {
            shark = candi;
            shark_eat++;
            if (shark_eat == shark_size)
            {
                shark_size++, shark_eat = 0;
            }
            maps[shark.y][shark.x] = 0;
        }
    }

    cout << shark.time << '\n';

    return 0;
}