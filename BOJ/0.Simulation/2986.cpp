//https://www.acmicpc.net/problem/2986
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int count = 0;

    for (int i = n - 1;; i--)
    {
        count += 1;
        if (n % i == 0)
            break;
    }

    cout << count << '\n';
    return 0;
}