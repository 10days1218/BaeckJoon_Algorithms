//https://www.acmicpc.net/problem/11729
#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int by, int to);
int main(void)
{
    int n;
    long long ans;
    cin >> n;

    ans = (long long)pow((double)2, (double)n) - 1;

    cout << ans << '\n';
    hanoi(n, 1, 2, 3);
    return 0;
}

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
        cout << from << " " << to << '\n';
    else
    {
        hanoi(n - 1, from, to, by);
        hanoi(1, from, by, to);
        hanoi(n - 1, by, from, to);
    }
}