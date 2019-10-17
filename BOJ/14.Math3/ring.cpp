//3036
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++)
    {
        int a, b = 0;
        int g = gcd(v[0], v[i]);
        if (v[0] > v[i])
            cout << v[0] / g << '/' << v[i] / g << '\n';
        else
            cout << v[0] / g << '/' << v[i] / g << '\n';
    }
    return 0;
}