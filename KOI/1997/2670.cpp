//https://www.acmicpc.net/problem/2670
#include <bits/stdc++.h>
using namespace std;

double numbers[10000];
int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    double best = numbers[0], one = numbers[0];

    for (int j = 1; j < n; j++)
    {
        if (numbers[j] > one * numbers[j])
            one = numbers[j];

        else
            one *= numbers[j];

        if (best < one)
            best = one;
    }

    cout.setf(ios::fixed);
    cout.precision(3);
    cout << best << '\n';

    return 0;
}