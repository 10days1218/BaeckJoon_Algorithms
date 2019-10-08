//#3190
#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int maps[101][101];
int answer = 0;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
queue<pair<int, char>> dir;
int main(void)
{
    cin >> n;
    cin >> k;

    maps[1][1] = 1;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        maps[r][c] = 2;
    }

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int t;
        char d;
        cin >> t >> d;
        dir.push({t, d});
    }

    cout << answer << '\n';

    return 0;
}