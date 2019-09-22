//#9461
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 0;
    vector<long long> v(101);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v[1] = v[2] = v[3] = 1;
        for (int i = 4; i <= tmp; i++)
        {
            v[i] = v[i - 3] + v[i - 2];
        }
        cout << v[tmp] << '\n';
    }
    return 0;
}