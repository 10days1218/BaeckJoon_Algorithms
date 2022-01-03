//https://www.acmicpc.net/problem/10834
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, answer = 1;
    int r = 0;
    cin >> n;

    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b)
        {
            answer = a == 1 ? b * answer : answer / a * b;
            r = r == c ? r = 0 : r = 1;
        }
        else
        {
            answer = answer / a * b;
            r = r == c ? r = 0 : r = 1;
        }
    }
    cout << r << " " << answer << '\n';

    return 0;
}