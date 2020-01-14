//https://www.acmicpc.net/problem/1722
#include <bits/stdc++.h>
using namespace std;

int numbers[20];

int main(void)
{
    int n, cmd;
    cin >> n >> cmd;

    if (cmd == 1)
    {
        int k;
        cin >> k;
    }

    else if (cmd == 2)
    {
        for (int i = 0; i < n; i++)
            cin >> numbers[i];
    }
    return 0;
}
