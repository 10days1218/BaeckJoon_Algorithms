//#11050
#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
int main(void)
{
    int n, k = 0;
    cin >> n >> k;

    cout << fact(n) / (fact(k) * fact(n - k)) << '\n';

    return 0;
}