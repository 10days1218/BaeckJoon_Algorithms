//https://www.acmicpc.net/problem/17779
#include <bits/stdc++.h>
using namespace std;

int population[21][21];
int maps[21][21];
int answer = INT_MAX;
int n;

void check(int x, int y);
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            cin >> population[x][y];

    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            check(x, y);

    cout << answer << '\n';
    return 0;
}

void check(int x, int y)
{
    int d1, d2;
    int maxValue = INT_MIN, minValue = INT_MAX;

    for (d1 = 1; d1 < n; d1++)
    {
        for (int d2 = 1; d2 < n; d2++)
        {
            if (x + d1 + d2 > n || y - d1 <= 0 || y + d2 > n)
                continue;

            fill(&maps[0][0], &maps[0][0] + 21 * 21, 0);
            int sum = 0;
            //경계선
            int i = 0;
            while (i <= d1)
            {
                maps[x + i][y - i] = 5;
                maps[x + d2 + i][y + d2 - i] = 5;
                i++;
            }

            i = 0;
            while (i <= d2)
            {
                maps[x + i][y + i] = 5;
                maps[x + d1 + i][y - d1 + i] = 5;
                i++;
            }

            //for(int)

            //첫 번째 구역
            for (int r = 1; r < x + d1; r++)
            {
                for (int c = 1; c <= y; c++)
                {
                    if (maps[r][c] == 5)
                        break;
                    sum += population[r][c];
                    maps[r][c] = 1;
                }
            }

            maxValue = maxValue < sum ? sum : maxValue;
            minValue = minValue > sum ? sum : minValue;
            sum = 0;

            //두 번째 구역
            for (int r = 1; r <= x + d2; r++)
            {
                for (int c = y + 1; c <= n; c++)
                {
                    if (maps[r][c] == 5)
                        continue;

                    sum += population[r][c];
                    maps[r][c] = 2;
                }
            }

            maxValue = maxValue < sum ? sum : maxValue;
            minValue = minValue > sum ? sum : minValue;
            sum = 0;

            //세 번째 구역
            for (int r = x + d1; r <= n; r++)
            {
                for (int c = 1; c < y - d1 + d2; c++)
                {
                    if (maps[r][c] == 5)
                        break;

                    sum += population[r][c];
                    maps[r][c] = 3;
                }
            }

            maxValue = maxValue < sum ? sum : maxValue;
            minValue = minValue > sum ? sum : minValue;
            sum = 0;

            //네 번째 구역
            for (int r = x + d2 + 1; r <= n; r++)
            {
                for (int c = y - d1 + d2; c <= n; c++)
                {
                    if (maps[r][c] == 5)
                        continue;
                    sum += population[r][c];
                    maps[r][c] = 4;
                }
            }

            maxValue = maxValue < sum ? sum : maxValue;
            minValue = minValue > sum ? sum : minValue;
            sum = 0;

            for (int r = 1; r <= n; r++)
            {
                for (int c = 1; c <= n; c++)
                {
                    if (maps[r][c] == 5)
                        sum += population[r][c];
                }
            }

            maxValue = maxValue < sum ? sum : maxValue;
            minValue = minValue > sum ? sum : minValue;

            answer = min(answer, maxValue - minValue);
        }
    }
}