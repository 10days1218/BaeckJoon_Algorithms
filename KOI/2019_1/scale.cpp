//https://www.acmicpc.net/problem/17610
#include <bits/stdc++.h>
using namespace std;

int numbers[13];
int flag[13];
vector<int> lists;
int m;
void powerset(int n, int depth);
int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    powerset(n, 0);

    // cout << m << ' ' << lists.size() << '\n';
    cout << m - lists.size() << '\n';
    return 0;
}

void powerset(int n, int depth)
{
    if (n == depth)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
            if (flag[i])
                res += numbers[i];

        if (res)
        {
            cout << res << '\n';
            lists.push_back(res);
        }
        m = max(res, m);
        return;
    }

    flag[depth] = 1;
    powerset(n, depth + 1);
    flag[depth] = 0;
    powerset(n, depth + 1);
}
