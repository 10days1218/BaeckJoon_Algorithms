#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int d[100005];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    answer = d[1] = a[1];

    for (int i = 2; i <= n; i++)
    {
        d[i] = max(d[i - 1] + a[i], a[i]);
        answer = max(answer, d[i]);
    }

    cout << answer << "\n";

    return 0;
}