//https://www.acmicpc.net/problem/13301
#include <bits/stdc++.h>
using namespace std;

long long number[82];
long long total[82];
int main(void)
{
    int n;
    cin >> n;
    number[1] = 1, number[2] = 1;

    if (n > 2)
        for (int i = 3; i <= n + 1; i++)
            number[i] = number[i - 1] + number[i - 2];

    total[1] = 4;

    for (int i = 2; i <= n; i++)
        total[i] = total[i - 1] + number[i] * 2;

    cout << total[n] << '\n';

    return 0;
}