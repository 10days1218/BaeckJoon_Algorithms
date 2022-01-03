//https://www.acmicpc.net/problem/10886
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    int cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (v)
            cnt++;
    }

    if (cnt > n / 2)
        cout << "Junhee is cute!\n";
    else
        cout << "Junhee is not cute!\n";

    return 0;
}