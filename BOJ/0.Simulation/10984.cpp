//https://www.acmicpc.net/problem/10984
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int testcase;
    int T;
    cin >> T;

    for (testcase = 0; testcase < T; testcase++)
    {
        int n, credit = 0;
        double GPA = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            double c, g;
            cin >> c >> g;
            credit += c, GPA += c * g;
        }
        cout << fixed;
        cout.precision(1);
        cout << credit << " " << GPA / credit << '\n';
    }

    return 0;
}