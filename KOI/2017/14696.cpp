//https://www.acmicpc.net/problem/14696
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for (int test_case = 0; test_case < n; test_case++)
    {
        int a[5], b[5];
        fill(a, a + 5, 0);
        fill(b, b + 5, 0);
        int aCase, bCase;
        cin >> aCase;

        for (int i = 0; i < aCase; i++)
        {
            int number;
            cin >> number;
            a[number] += 1;
        }

        cin >> bCase;

        for (int i = 0; i < bCase; i++)
        {
            int number;
            cin >> number;
            b[number] += 1;
        }

        for (int i = 4; i >= 1; i--)
        {
            if (a[i] > b[i])
            {
                cout << "A\n";
                break;
            }
            else if (a[i] < b[i])
            {
                cout << "B\n";
                break;
            }

            else if (i == 1)
            {
                cout << "D\n";
                break;
            }
        }
    }
    return 0;
}