//#1712
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A, B, C, Ns = 0;
    cin >> A >> B >> C;

    if (C - B <= 0)
        cout << -1 << endl;

    else
        cout << A / (C - B) + 1 << endl;
    return 0;
}