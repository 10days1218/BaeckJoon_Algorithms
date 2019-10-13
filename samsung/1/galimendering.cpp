//#17471
#include <bits/stdc++.h>
using namespace std;

int n;
int people[11];
int link[11][11];
bool check[11];
int answer = INT_MAX;

bool isConnected(int index)
{
    vector<int> v;
    int selected[11];
    queue<int> q;

    fill_n(selected, 11, 0);

    if (index == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                v.push_back(i);
            }
        }

        if (v.size() == 1)
        {
            return true;
        }

        for (int i = 1; i < v.size(); i++)
        {
            selected[v[i]] = 1;
        }

        q.push(v[0]);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            //selected[hear] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (link[i][j] == 1 && selected[j] == 1)
                {
                    selected[j] = 0;
                    q.push(j);
                }
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (selected[i] == 1)
            {
                flag = false;
                break;
            }
        }

        return flag;
    }

    if (index == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                v.push_back(i);
            }
        }

        if (v.size() == 1)
        {
            return true;
        }

        for (int i = 1; i < v.size(); i++)
        {
            selected[v[i]] = 1;
        }

        q.push(v[0]);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            for (int j = 1; j <= n; j++)
            {
                if (link[i][j] == 1 && selected[j] == 1)
                {
                    selected[j] = 0;
                    q.push(j);
                }
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (selected[i] == 1)
            {
                flag = false;
                break;
            }
        }

        return flag;
    }
}
void dfs(int cnt, int pick, int idx)
{
    if (cnt == pick)
    {
        bool connect1 = isConnected(1);
        bool connect2 = isConnected(2);

        if (connect1 && connect2)
        {
            int total1 = 0, total2 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (check[i])
                    total1 += people[i];
                else
                    total2 += people[i];
            }

            answer = min(answer, abs(total1 - total2));
        }
        return;
    }

    for (int i = idx; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            dfs(cnt + 1, pick, idx + 1);
            check[i] = false;
        }
    }
}
int main(void)
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> people[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int e;
            cin >> e;
            link[i][e] = 1;
            link[e][i] = 1;
        }
    }

    for (int i = 1; i <= n / 2; i++)
    {
        fill_n(check, 11, false);
        dfs(0, i, 1);
    }

    if (answer == INT_MAX)
        answer = -1;
    cout << answer << '\n';
    return 0;
}