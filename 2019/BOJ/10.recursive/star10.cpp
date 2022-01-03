//https://www.acmicpc.net/problem/2447
#include <bits/stdc++.h>
using namespace std;

char maps[2187][2187];
int n;

void init();
void printMaps();
void solve(int y, int x, int n);

int main(void)
{
    init();
    cin >> n;

    solve(0, 0, n);
    printMaps();

    return 0;
}

void solve(int y, int x, int n)
{
    if (n == 1)
    {
        maps[y][x] = '*';
        return;
    }

    int div = n / 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            solve(y + (div * i), x + (div * j), div); // 3으로 나누어서 문제를 해결
        }
    }
    return;
}

void init()
{
    for (int i = 0; i < 2187; i++)
        for (int j = 0; j < 2187; j++)
            maps[i][j] = ' ';
}

void printMaps()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << maps[i][j];
        }
        cout << '\n';
    }
}
