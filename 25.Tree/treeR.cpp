#include <bits/stdc++.h>
using namespace std;

string board[100][100];
int main(void)
{
    int n, k;
    int check = 1;
    cin >> n >> k;

    check = k < 0 ? 1 : -1;
    k = check == -1 ? k * (-1) : k;
    k = k % n;

    if (n % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == n / 2)
                continue;
            if (check == 1) // 시계 방향
            {
                for (int j = 0; j < k; j++)
                {
                    if (j == 0)
                    {
                        ;
                    }
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    ;
                }
            }
            check *= -1;
        }
    }

    else
    {
        ;
    }

    return 0;
}