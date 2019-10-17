//#2004
#include <bits/stdc++.h>
using namespace std;

int two(int n)
{
    int count = 0;
    for (long long i = 2; n / i >= 1; i *= 2)
        count += n / i;

    return count;
}

int five(int n)
{
    int count = 0;
    for (long long i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, answer;
    int fiv, tw;
    cin >> n >> m;

    fiv = five(n) - five(m) - five(n - m);
    tw = two(n) - two(m) - two(n - m);

    answer = min(fiv, tw);
    cout << answer << '\n';

    return 0;
}