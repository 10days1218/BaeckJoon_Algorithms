//#1676
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int answer = 0;
    int a[2] = {0};
    int n, tmp;

    cin >> n;

    a[0] = 1;

    for (int i = 4; i <= n; i++)
    {
        tmp = i;
        for (int j = 2; j <= tmp; j++)
        {
            while (tmp % j == 0)
            {
                if (j == 2)
                    a[0]++;

                if (j == 5)
                    a[1]++;

                tmp /= j;
            }
                }
    }

    answer = min(a[0], a[1]);

    cout << answer << '\n';

    return 0;
}