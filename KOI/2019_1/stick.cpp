//https://www.acmicpc.net/problem/17608
#include <bits/stdc++.h>
using namespace std;

int stick[100001];
int main(void)
{
    int T;
    int answer = 0;
    int m = 0;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> stick[i];
    }

    for (int i = T - 1; i >= 0; i--)
    {
        if (m < stick[i])
        {
            m = stick[i];
            answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}