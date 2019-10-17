//#2630
#include <bits/stdc++.h>
using namespace std;

int blue = 0;
int white = 0;
int arr[129][129] = {0};

void paper(int x, int y, int l)
{
    int check = arr[x][y];

    for (int i = x; i < x + l; i++)
    {
        for (int j = y; j < y + l; j++)
        {
            if (arr[i][j] != check)
            {
                paper(x, y, l / 2);
                paper(x, y + l / 2, l / 2);
                paper(x + l / 2, y, l / 2);
                paper(x + l / 2, y + l / 2, l / 2);
                return;
            }
        }
    }

    if (check == 1)
        blue++;
    else
        white++;
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    paper(0, 0, n);

    cout << white << '\n'
         << blue << '\n';

    return 0;
}
