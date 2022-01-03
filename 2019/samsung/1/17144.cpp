//https://www.acmicpc.net/problem/17144
#include <bits/stdc++.h>
using namespace std;

struct CLEANER
{
    int r1;
    int r2;
};

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int maps[50][50];
int R, C, T;
CLEANER cleaner;

void spread();
void clean();
int main(void)
{
    int testcase;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    cin >> testcase;

    for (int t = 1; t <= testcase; t++)
    {
        int answer = 0;
        cin >> R >> C >> T;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> maps[i][j];
                if (maps[i][j] == -1)
                {
                    if (cleaner.r1 == 0)
                        cleaner.r1 = i;
                    else
                        cleaner.r2 = i;
                }
            }
        }

        for (int t = 0; t < T; t++)
        {
            spread();
            clean();
        }

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (maps[i][j] != -1)
                    answer += maps[i][j];

        cout << "# " << testcase << " " << answer << '\n';
        return 0;
    }
}

void spread()
{
    int maps2[50][50];
    fill(&maps2[0][0], &maps2[0][0] + 50 * 50, 0);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int cnt = 0;
            if (maps[i][j] == -1 || maps[i][j] == 0)
                continue;

            for (int dir = 0; dir < 4; dir++)
            {
                int nY = i + dy[dir], nX = j + dx[dir];

                if (nY < 0 || nY >= R || nX < 0 || nX >= C || maps[nY][nX] == -1)
                    continue;

                maps2[nY][nX] += maps[i][j] / 5;
                cnt++;
            }
            maps[i][j] = maps[i][j] - maps[i][j] / 5 * cnt;
        }
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            maps[i][j] += maps2[i][j];
}

void clean()
{
    //↓
    for (int i = 0; i < cleaner.r1 - 1; i++)
        maps[i + 1][0] = maps[i][0];

    //←
    for (int i = 1; i <= R; i++)
        maps[0][i - 1] = maps[0][i];

    //↑
    for (int i = 1; i <= cleaner.r1; i++)
        maps[i - 1][C - 1] = maps[i][C - 1];

    //→
    for (int i = C - 1; i > 0; i--)
        maps[cleaner.r1][i] = maps[cleaner.r1][i - 1];

    maps[cleaner.r1][1] = 0;

    //↑
    for (int i = cleaner.r2 + 1; i < R - 1; i++)
        maps[i][0] = maps[i + 1][0];

    //←
    for (int i = 0; i < C - 1; i++)
        maps[R - 1][i] = maps[R - 1][i + 1];

    //↓
    for (int i = R - 1; i > cleaner.r2; i--)
        maps[i][C - 1] = maps[i - 1][C - 1];

    //→
    for (int i = C - 1; i > 0; i--)
        maps[cleaner.r2][i] = maps[cleaner.r2][i - 1];

    maps[cleaner.r2][1] = 0;
}
