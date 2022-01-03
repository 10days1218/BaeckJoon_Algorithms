//https://www.acmicpc.net/problem/15970
#include <bits/stdc++.h>
using namespace std;

// struct POINT
// {
//     int pos;
//     int color;
// };

// map<int, vector<int>> maps;
vector<int> maps[5005];
int main(void)
{
    int n;
    int ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int pos, color;
        cin >> pos >> color;

        // if (maps.count(color) == 0)
        maps[color - 1].push_back(pos);
    }

    for (int i = 0; i < n; i++)
        sort(maps[i].begin(), maps[i].end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            int prev, next;
            prev = next = INT_MAX;
            if (j > 0)
                prev = maps[i][j] - maps[i][j - 1];

            if (j + 1 < maps[i].size())
                next = maps[i][j + 1] - maps[i][j];
            ans += min(prev, next);
        }
    }

    cout << ans << '\n';

    return 0;
}