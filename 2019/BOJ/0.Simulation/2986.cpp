//https://www.acmicpc.net/problem/2986
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    int answer = 1;
    cin >> n;

    int count = 0;
    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            if (i != n && n / i != n && (answer < i || answer < n / i))
                answer = i > n / i ? i : n / i;
        }
    }

    if (n == i * i)
        if (answer < i)
            answer = i;

    cout << n - answer << '\n';
    return 0;
}