//#26009
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << '\n'
         << lcm(n, m) << '\n';
    return 0;
}