//#15686
#include <bits/stdc++.h>
using namespace std;

struct POS
{
    int y;
    int x;
};

int n, m;
int maps[50][50];
bool pick[13];
int ans = INT_MAX;
vector<POS> v;
vector<POS> h;

void dfs(int cnt, int idx)
{
    if (cnt == m)
    {
        int total = 0;

        for (int i = 0; i < h.size(); i++)
        {
            int min_dis = INT_MAX;
            for (int j = 0; j < v.size(); j++)
            {
                if (pick[j])
                {
                    int tmp = abs(h[i].y - v[j].y) + abs(h[i].x - v[j].x);
                    min_dis = min(min_dis, tmp);
                }
            }
            total += min_dis;
        }

        ans = min(ans, total);
        return;
    }

    for (int i = idx; i < v.size(); i++)
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
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];

            if (maps[i][j] == 1)
            {
                POS t;
                t.y = i, t.x = j;
                h.push_back(t);
            }

            else if (maps[i][j] == 2)
            {
                POS t;
                t.y = i, t.x = j;
                v.push_back(t);
            }
        }
    }

    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}