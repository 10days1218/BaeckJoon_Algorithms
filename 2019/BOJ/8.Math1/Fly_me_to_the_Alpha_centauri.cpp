//#1011
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase = 0;
    cin >> testCase;

    while (testCase--)
    {
        int x, y;
        cin >> x >> y;
        long long v = 1;
        while (v * v <= (y - x))
            v++;
        v -= 1;

        long long answer = (y - x) - v * v;
        answer = (long long)ceil((double)answer / (double)v);

        cout << v * 2 - 1 + answer << '\n';
    }
    return 0;
}
