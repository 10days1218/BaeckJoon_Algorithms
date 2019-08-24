//#1217 거듭 제곱
#include <bits/stdc++.h>
using namespace std;

int power(int n, int m, int ans)
{
    if (m == 0)
    {
        return ans;
    }

    else
    {
        ans *= n;
        m--;
        power(n, m, ans);
    }
}
int main(void)
{

    for (int i = 1; i <= 10; i++)
    {
        int t, n, m;
        cin >> t;
        cin >> n >> m;
        cout << '#' << t << ' ' << power(n, m, 1) << '\n';
    }
    return 0;
}