//https://www.acmicpc.net/problem/17822
#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int gear[50][50];
const int dy[] = {};
const int dx[] = {};

void turn(int x, int d, int k);
int removeNumber();
void addNumber();
int main(void)
{
    cin >> N >> M >> T;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> gear[i][j];

    for (int tc = 0; tc < T; tc++)
    {
        int x, d, k;
        cin >> x >> d >> k;
        x = x - 1, k = k % M;
        turn(x, d, k);
        int count = removeNumber();

        if (count == 0)
        {
            addNumber(); //double...
        }
    }
    return 0;
}

void turn(int x, int d, int k)
{
    for (int tc = 0; tc < k; tc++)
    {
        for (int i = 0; i < N; i++)
        {
            if (i % x != 0)
                continue;

            if (d == 0) // 시계
            {
                int tmp = gear[i][M - 1];
                for (int j = M - 1; j > 0; j--)
                    gear[i][j] = gear[i][j - 1];

                gear[i][0] = tmp;
            }

            else // 반시계
            {
                int tmp = gear[i][0];
                for (int j = 0; j < M - 1; j++)
                    gear[i][j] = gear[i][j + 1];

                gear[i][M - 1] = tmp;
            }
        }
    }
}

int removeNumber()
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int number = gear[i][j];
            for (int dir = 0; dir < 5; dir++)
            {
                int nY = i + dy[dir], nX = j + dx[dir];
                // if (nY < 0 || n)
                // {
                //     ;
                // }
            }
        }
    }
}

void addNumber()
{
    ;
}