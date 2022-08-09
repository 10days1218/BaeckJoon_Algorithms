#include <bits/stdc++.h>
using namespace std;

int n, m;
int s[100005];
int d[100005];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        d[i] = d[i - 1] + s[i];
    }

    for (int j = 0; j < m; j++)
    {
        int s, e;
        cin >> s >> e;
        cout << d[e] - d[s - 1] << "\n";
    }
    return 0;
}