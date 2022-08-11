#include <bits/stdc++.h>
using namespace std;

int count1, count2;
int n;
int fib(int n)
{
    if (n == 1 || n == 2)
    {
        count1++;
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n)
{
    int f[40] = {0};
    f[1] = f[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        count2++;
    }

    return f[n];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    fib(n);
    fibonacci(n);

    cout << count1 << " " << count2 << "\n";

    return 0;
}