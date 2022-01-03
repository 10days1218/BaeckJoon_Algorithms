//https://www.acmicpc.net/problem/1789
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n;
    long long num = 1;
    int ans = 0;
    long long sum = 0;

    cin >> n;

    while (1)
    {
        sum += num;
        ans++;
        if (sum > n)
        {
            ans--;
            break;
        }
        num++;
    }

    cout << ans << '\n';
    return 0;
}