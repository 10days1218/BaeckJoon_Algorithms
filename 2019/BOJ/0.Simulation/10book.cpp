//https://www.acmicpc.net/problem/5565
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int total = 0;
    int nine = 0;

    cin >> total;

    for (int i = 0; i < 9; i++)
    {
        int v;
        cin >> v;
        nine += v;
    }

    cout << total - nine << '\n';

    return 0;
}