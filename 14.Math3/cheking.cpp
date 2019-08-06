//#2981
#include <bits/stdc++.h>
using namespace std;

int gcm(int x, int y)
{
    int n;
    while (1)
    {
        n = x % y;
        if (n == 0)
            return y;
        x = y;
        y = n;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[101] = {0};
    int m[101];
    int j, g = 0;
    vector<int> answer;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            m[i] = abs(arr[i] - arr[0]);
        else
            m[i] = abs(arr[i] - arr[i + 1]);
    }

    g = m[0];

    for (int i = 1; i < n; i++)
        g = gcm(g, m[i]);

    for (j = 1; j * j < g; j++)
    {
        if (g % j == 0)
        {
            answer.push_back(j);
            answer.push_back(g / j);
        }
    }

    if (j * j == g)
        answer.push_back(j);

    answer.erase(answer.begin());
    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';

    return 0;
}