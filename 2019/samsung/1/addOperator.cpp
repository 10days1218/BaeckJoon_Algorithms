//#14888
#include <bits/stdc++.h>
using namespace std;

int arr[12];
int op[4];
int ans_max = INT_MIN, ans_min = INT_MAX;
int n;

int dfs(int idx, int amount)
{
    if (idx == n)
    {
        ans_max = max(ans_max, amount);
        ans_min = min(ans_min, amount);
        return 0;
    }

    if (op[0] > 0)
    {
        op[0]--;
        dfs(idx + 1, amount + arr[idx]);
        op[0]++;
    }
    if (op[1] > 0)
    {
        op[1]--;
        dfs(idx + 1, amount - arr[idx]);
        op[1]++;
    }
    if (op[2] > 0)
    {
        op[2]--;
        dfs(idx + 1, amount * arr[idx]);
        op[2]++;
    }
    if (op[3] > 0)
    {
        op[3]--;
        dfs(idx + 1, amount / arr[idx]);
        op[3]++;
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    dfs(1, arr[0]);

    cout << ans_max << '\n';
    cout << ans_min << '\n';

    return 0;
}