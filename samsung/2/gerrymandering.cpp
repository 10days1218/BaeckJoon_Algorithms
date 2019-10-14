//#17471
#include <bits/stdc++.h>
using namespace std;

int n;
int people[10];
int a[10][10];
bool pick[10];
int ans = INT_MAX;
bool isConnected(vector<int> &v)
{
    int check[10];
    fill_n(check, 10, 0);

    if (v.size() == 1)
        return true;

    for (int i = 1; i < v.size(); i++)
    {
        check[v[i]] = 1;
    }

    queue<int> q;
    q.push(v[0]);

    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1 && check[j] == 1)
            {
                check[j] = 0;
                q.push(j);
            }
        }
    }

    int flag = true;
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 1)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void dfs(int cnt, int idx, int p)
{
    if (cnt == p)
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

        int check1 = isConnected(v1);
        int check2 = isConnected(v2);
        if (check1 && check2)
        {
            int t1 = 0, t2 = 0;

            for (int i = 0; i < n; i++)
            {
                if (pick[i])
                {
                    t1 += people[i];
                }
                else
                {
                    t2 += people[i];
                }
            }
            ans = min(ans, abs(t1 - t2));
        }
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (!pick[i])
        {
            pick[i] = true;
            dfs(cnt + 1, idx + 1, p);
            pick[i] = false;
        }
    }
}
int main(void)
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> people[i];

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            int e;
            cin >> e;
            e--;
            a[i][e] = 1, a[e][i] = 1;
        }
    }

    for (int i = 1; i <= n / 2; i++)
    {
        fill_n(pick, 10, false);
        dfs(0, 0, i);
    }

    if (ans == INT_MAX)
        ans = -1;
    cout << ans << '\n';
    return 0;
}