#include <iostream>

#include <algorithm>

#include <cstring>

using namespace std;

char map[52][52];

int n, m, sx, sy;

int chk[52][52];

int xrr[4] = {0, 0, 1, -1};

int yrr[4] = {1, -1, 0, 0};

int ok = 0;

bool range(int rx, int ry)

{

    if (rx < 0 || ry < 0 || rx > n - 1 || ry > m - 1)

        return false;

    else

        return true;
}

void dfs(int x, int y, int cnt, int color)

{

    if (ok)
        return;

    for (int i = 0; i < 4; i++)

    {

        int cx = x + xrr[i];

        int cy = y + yrr[i];

        if (range(cx, cy))

        {

            if (chk[cx][cy] == false) //방문되어있지않았다면

            {

                if (map[cx][cy] == color) //같은색이면 탐색

                {

                    chk[cx][cy] = true;

                    dfs(cx, cy, cnt + 1, color); //개수 늘리고
                }
            }

            else

            {

                if (cnt >= 4 && sx == cx && sy == cy)

                {

                    ok = 1;

                    return;
                }
            }
        }
    }
}

int main()

{

    cin >> n >> m;

    for (int i = 0; i < n; i++)

    {

        for (int j = 0; j < m; j++)

        {

            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)

    {

        for (int j = 0; j < m; j++)

        {

            memset(chk, false, sizeof(chk));

            sx = i;

            sy = j;

            chk[sx][sy] = true;

            dfs(i, j, 1, map[i][j]);

            if (ok)

            {

                cout << "Yes" << endl;

                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}