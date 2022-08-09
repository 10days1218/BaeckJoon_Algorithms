#include <bits/stdc++.h>
using namespace std;

int n;
int D[1005][3];
int S[1005][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> S[i][j];

    for (int i = 1; i <= n; i++)
    {
        D[i][0] = min(D[i - 1][1], D[i - 1][2]) + S[i][0];
        D[i][1] = min(D[i - 1][0], D[i - 1][2]) + S[i][1];
        D[i][2] = min(D[i - 1][0], D[i - 1][1]) + S[i][2];
    }

    cout << min(min(D[n][0], D[n][1]), D[n][2]) << "\n";
    return 0;
}