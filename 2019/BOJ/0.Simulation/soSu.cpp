//https://www.acmicpc.net/problem/2960
#include <bits/stdc++.h>
using namespace std;

bool number[1001];
int main(void)
{
    int n, k = 0;
    int cnt = 0;
    vector<int> ans;
    cin >> n >> k;

    fill_n(number, 1001, true);
    number[0] = number[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (number[i])
        {
            number[i] = false;
            ans.push_back(i);
            for (int j = i * 2; j <= n; j += i)
            {
                if (number[j])
                {
                    number[j] = false;
                    ans.push_back(j);
                }
            }
        }
    }

    cout << ans[k - 1] << '\n';
    return 0;
}