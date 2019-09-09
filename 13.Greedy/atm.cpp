//#11399
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, answer = 0;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            answer += v[j];
        }
    }

    cout << answer << '\n';

    return 0;
}