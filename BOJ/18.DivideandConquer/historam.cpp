//https://www.acmicpc.net/problem/1725
#include <bits/stdc++.h>
using namespace std;

int h[100000];

int solve(int left, int right);
int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> h[i];

    return 0;
}

int solve(int left, int right)
{
    if (left == right)
        return h[left];

    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid + 1, right));
}