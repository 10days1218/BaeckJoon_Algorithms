//https://www.acmicpc.net/problem/15969
#include <bits/stdc++.h>
using namespace std;

int n;
int numbers[1000];
int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    sort(numbers, numbers + n);

    cout << numbers[n - 1] - numbers[0] << '\n';
    return 0;
}