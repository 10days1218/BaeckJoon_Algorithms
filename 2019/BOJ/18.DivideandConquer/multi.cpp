//https://www.acmicpc.net/problem/1629
#include <bits/stdc++.h>
using namespace std;

long long power(int a, int b, int c);
int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    int ret = power(a % c, b, c);
    cout << ret << '\n';
    return 0;
}

long long power(int a, int b, int c)
{
    if (b == 1)
        return a;

    long long tmp = power(a, b / 2, c);
    if (b % 2)
    {
        return (((tmp * tmp) % c) * a) % c;
    }

    else
    {
        return (tmp * tmp) % c;
    }
}