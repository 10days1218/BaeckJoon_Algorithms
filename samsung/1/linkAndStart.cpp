//#15661
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[21][21];
int pick[21];
int ans = INT_MAX;

int totalValue(vector<int> v)
{
    int total = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int l = v[i];
        for (int j = 0; j < v.size(); j++)
        {
            if (i == j)
                continue;
            int m = v[j];

            total += arr[l][m];
        }
    }

    return total;
}

void dfs(int cnt, int idx)
{
    if (cnt == n / 2)
    {
        vector<int> v1, v2;
        for (int i = 0; i < n; i++)
        {
            if (pick[i])
            {
                v1.push_back(i);
            }

            else
            {
                v2.push_back(i);
            }
        }

        int total1 = totalValue(v1);
        int total2 = totalValue(v2);
        ans = min(ans, abs(total1 - total2));
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (!pick[i])
        {
            pick[i] = true;
            dfs(cnt + 1, i + 1);
            pick[i] = false;
        }
    }
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << '\n';
    return 0;
}