//https://www.acmicpc.net/problem/1780
#include <bits/stdc++.h>
using namespace std;

int n;
int paper[2187][2187];
int ans[3];

void countPaper(int y, int x, int l)
{
    int value = paper[y][x];

    for (int i = y; i < y + l; i++)
    {
        for (int j = x; j < x + l; j++)
        {
            if (value != paper[i][j])
            {
                countPaper(y, x, l / 3);
                countPaper(y, x + l / 3, l / 3);
                countPaper(y, x + l / 3 * 2, l / 3);
                countPaper(y + l / 3, x, l / 3);
                countPaper(y + l / 3 * 2, x, l / 3);
                countPaper(y + l / 3, x + l / 3, l / 3);
                countPaper(y + l / 3, x + l / 3 * 2, l / 3);
                countPaper(y + l / 3 * 2, x + l / 3, l / 3);
                countPaper(y + l / 3 * 2, x + l / 3 * 2, l / 3);
                return;
            }
        }
    }

    if (value == -1)
        ans[0] += 1;
    if (value == 0)
        ans[1] += 1;
    if (value == 1)
        ans[2] += 1;
}
int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];

    countPaper(0, 0, n);

    for (int i = 0; i < 3; i++)
        cout << ans[i] << '\n';
    return 0;
}