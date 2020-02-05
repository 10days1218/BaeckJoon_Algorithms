//https://www.acmicpc.net/problem/17779
#include <bits/stdc++.h>
using namespace std;

int population[20][20];
int maps[20][20];
int answer = 0;
int n;

void check(int x, int y);
int main(void)
{
    cin >> n;

    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            cin >> population[x][y];

    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            check(x, y);

    return 0;
}

void check(int x, int y)
{
    int d1, d2;
    fill(maps[0][0], maps[0][0] + 20 * 20, 0);

    for (d1 = 1; d1 < n; d1++)
    {
        for (int d2 = 1; d2 < n; d2++)
        {
            if (x + d1 + d2 - 1 >= n || y - d1 - 1 < 0 || y + d2 >= n)
                continue;

            //1첫번째 구역
            for (int r = 0; r < x + d1 - 1; r++)
                for (int c = 0; c < y; c++)
                    maps[r][c] = 1;

            for (int r = 0; r < x + d2; r++)
            {
                
            }
        }
    }
}