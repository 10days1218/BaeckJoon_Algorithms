//#3431 준환이의 운동관리
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> L(n);
    vector<int> U(n);
    vector<int> X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> L[i] >> U[i] >> X[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (X[i] >= L[i] && X[i] <= U[i])
        {
            cout << '#' << i + 1 << ' ' << 0 << '\n';
        }

        if (X[i] < L[i])
        {
            cout << '#' << i + 1 << ' ' << L[i] - X[i] << '\n';
        }

        if (X[i] > U[i])
        {
            cout << '#' << i + 1 << ' ' << -1 << '\n';
        }
    }
    return 0;
}