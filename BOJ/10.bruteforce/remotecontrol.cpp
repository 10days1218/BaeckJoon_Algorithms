//#1107
#include <bits/stdc++.h>
using namespace std;

int remote[10];

int check(int n);
int main(void)
{
    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int number;
        cin >> number;
        remote[number] = 1;
    }

    int res = abs(n - 100);
    for (int i = 0; i <= 1000000; i++)
    {
        int ch = i;
        int len = check(ch);
        if (len > 0)
        {
        }
    }

    return 0;
}

int check(int n)
{
}