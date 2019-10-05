//#14503
#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d;
int copy_d;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int maps[51][51];
int answer;

void bfs(int r, int c)
{
    int R = r;
    int C = c;
    while (1)
    {
        int i = 0;
        if (maps[R][C] == 0)
        {
            maps[R][C] = -1;
            answer++;
        }

        for (i = 0; i < 4; i++)
        {
            int next_dir = d == 0 ? 3 : d - 1;
            int nR = R + dir[next_dir][0];
            int nC = C + dir[next_dir][1];
            if (nR >= 0 && nR < n && nC >= 0 && nC < m && maps[nR][nC] == 0)
            {
                R = nR, C = nC;
                d = next_dir;
                break;
            }
            else
            {
                d = next_dir;
            }
        }

        if (i == 4)
        {
            int nR = R + (-1) * dir[d][0];
            int nC = C + (-1) * dir[d][1];
            if (nR >= 0 && nR < n && nC >= 0 && nC < m)
            {
                if (maps[nR][nC] == 1)
                {
                    break;
                }
                else
                {
                    R = nR, C = nC;
                }
            }
        }
    }
}
int main(void)
{
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
        }
    }

    bfs(r, c);
    cout << answer << '\n';

    return 0;
}