//https://www.acmicpc.net/problem/2659
#include <bits/stdc++.h>
using namespace std;

int number[4];

int solve(int n);
int main(void)
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
        cin >> number[i];

    int res = solve(number[0] * 1000 + number[1] * 100 + number[2] * 10 + number[3]);

    for (int i = 1111; i <= res; i++)
    {
        if (i == solve(i))
            ans++;
        
    }

    cout << ans << '\n';
    return 0;
}

int solve(int n)
{
    int temp = n;
    for (int i = 0; i < 3; i++)
    {
        n = n % 1000 * 10 + n / 1000;
        if (temp > n)
            temp = n;
    }

    return temp;
}