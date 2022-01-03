//https://www.acmicpc.net/problem/2822
#include <bits/stdc++.h>
using namespace std;

struct SCORE
{
    int score;
    int num;

    bool operator<(const SCORE &a) const
    {
        return score > a.score;
    }
};

SCORE p[8];
int ans[5];
int main(void)
{

    for (int i = 0; i < 8; i++)
    {
        cin >> p[i].score;
        p[i].num = i + 1;
    }

    stable_sort(p, p + 8);

    int total = 0;

    for (int i = 0; i < 5; i++)
    {
        total += p[i].score;
        ans[i] = p[i].num;
    }

    sort(ans, ans + 5);

    cout << total << '\n';

    for (int i = 0; i < 5; i++)
        cout << ans[i] << " ";

    cout << '\n';

    return 0;
}
