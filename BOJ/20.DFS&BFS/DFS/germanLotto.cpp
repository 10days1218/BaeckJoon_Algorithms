//https://www.acmicpc.net/problem/6603
#include <bits/stdc++.h>
using namespace std;

int number[13];
// bool pick[13];
vector<int> ans;

void lotto(int pick, int n);
int main(void)
{
    int n;
    while (1)
    {
        cin >> n;

        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            cin >> number[i];

        lotto(0, n);
        cout << '\n';
        fill(number, number + 13, 0);
    }
    return 0;
}

void lotto(int p, int n)
{

    if (p == 6)
    {

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';

        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || number[i] > ans.back())
        {
            ans.push_back(number[i]);
            lotto(p + 1, n);
            ans.pop_back();
        }
    }
}