//https://www.acmicpc.net/problem/14697
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b, c, number;
    cin >> a >> b >> c >> number;

    int cnt = number / a;

    for (int i = 0; i <= 300; i++)
    {
        for (int j = 0; j <= 300; j++)
        {
            for (int k = 0; k <= 300; k++)
            {
                if (a * i + b * j + c * k == number)
                {
                    cout << "1\n";
                    exit(0);
                }
            }
        }
    }

    cout << "0\n";

    return 0;
}