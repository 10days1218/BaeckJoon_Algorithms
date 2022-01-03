//https://www.acmicpc.net/problem/1722
#include <bits/stdc++.h>
using namespace std;

long long fibo[21];
bool check[21];
int numbers[21];

inline void init();
int main(void)
{
    init();

    int n, cmd;
    cin >> n;
    cin >> cmd;

    if (cmd == 1)
    {
        long long k;
        cin >> k;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (check[j] == true)
                    continue;

                if (fibo[n - i - 1] < k)
                    k -= fibo[n - i - 1];

                else
                {
                    check[j] = true;
                    numbers[i] = j;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
            cout << numbers[i] << " ";
        cout << '\n';
    }

    else if (cmd == 2)
    {
        long long ans = 1;
        for (int i = 0; i < n; i++)
            cin >> numbers[i];

        for (int i = 0; i < n; i++)
        {
            int number = numbers[i];
            for (int j = 1; j < number; j++)
            {
                if (check[j] == false)
                    ans += fibo[n - i - 1];
            }
            check[number] = true;
        }
        cout << ans << '\n';
    }

    return 0;
}

inline void init()
{
    fibo[0] = 1, fibo[1] = 1;
    for (int i = 2; i <= 20; i++)
        fibo[i] = fibo[i - 1] * i;
}
