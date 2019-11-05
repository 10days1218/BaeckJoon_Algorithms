//https://www.acmicpc.net/problem/2490
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int y[4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> y[j];

        int n = 0;
        for (int j = 0; j < 4; j++)
            if (y[j] == 1)
                n += 1;
        if (n == 0)
            cout << "D\n";
        else if (n == 1)
            cout << "C\n";
        else if (n == 2)
            cout << "B\n";
        else if (n == 3)
            cout << "A\n";
        else if (n == 4)
            cout << "E\n";
    }

    return 0;
}