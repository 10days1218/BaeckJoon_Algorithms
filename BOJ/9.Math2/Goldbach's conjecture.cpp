//#9020
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, n1, n2 = 0;
    vector<int> v;
    vector<bool> p(10000, true);
    p[0] = p[1] = false;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }

    for (int i = 2; i < 100; i++)
    {
        if (p[i])
        {
            for (int j = i * 2; j <= 10000; j += i)
                p[j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = v[i];
        n1 = n2 = v[i] / 2;
        while (n1 > 0 && n2 > 0)
        {
            if (p[n1] && p[n2])
            {
                cout << n1 << ' ' << n2 << '\n';
                break;
            }
            if (n1 % 2 == 0)
            {
                n1 -= 1;
                n2 += 1;
            }
            else
            {
                n1 -= 2;
                n2 += 2;
            }
        }
    }

    return 0;
}