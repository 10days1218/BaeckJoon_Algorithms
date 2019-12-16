//https://www.acmicpc.net/problem/3085
#include <bits/stdc++.h>
using namespace std;

char maps[50][50];
int n;
int ans = 0;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
void findCandy(int y, int x, int nY, int nX);
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maps[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nY = i + dy[dir], nX = j + dx[dir];
                if (nY < 0 || nY >= n || nX < 0 || nX >= n)
                    continue;

                if (maps[i][j] != maps[nY][nX])
                {
                    findCandy(i, j, nY, nX);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

void findCandy(int y, int x, int nY, int nX)
{
    char mapsCopy[50][50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mapsCopy[i][j] = maps[i][j];
        }
    }

    char swap1 = mapsCopy[y][x];
    mapsCopy[y][x] = mapsCopy[nY][nX];
    mapsCopy[nY][nX] = swap1;

    for (int i = 0; i < n; i++)
    {
        int start = mapsCopy[i][0];
        int cnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (start != mapsCopy[i][j])
            {
                start = mapsCopy[i][j];
                ans = max(cnt, ans);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        ans = max(cnt, ans);
    }

    for (int i = 0; i < n; i++)
    {
        int start = mapsCopy[0][i];
        int cnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (start != mapsCopy[j][i])
            {
                start = mapsCopy[j][i];
                ans = max(cnt, ans);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        ans = max(cnt, ans);
    }
}