//acmicpc.net/problem/1654
#include <bits/stdc++.h>
using namespace std;

int n, k;
long long lane[10000];
int main(void)
{
    cin >> k >> n;

    long long low = 1;
    long long upper = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> lane[i];
        upper = max(upper, lane[i]);
    }

    long long ans = 0;
    long long mid = 0;

    while (low <= upper)
    {
        long long tmp = 0;
        mid = (low + upper) / 2;
        for (int i = 0; i < k; i++)
        {
            tmp += lane[i] / mid;
        }

        if (tmp >= n)
        {
            low = mid + 1;
            if (mid > ans)
                ans = mid;
        }
        else
            upper = mid - 1;
    }

    cout << ans << '\n';
    return 0;
}