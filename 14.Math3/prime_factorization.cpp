//#116653
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 0;

    cin >> n;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << endl;
            n /= i;
        }
    }

    if (n > 1)
        cout << n << '\n';

    return 0;
}