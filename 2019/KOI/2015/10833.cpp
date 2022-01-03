//https://www.acmicpc.net/problem/10833
#include <bits/stdc++.h>
using namespace std;

int student[100];
int apple[100];
int main(void)
{
    int n, answer = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> student[i] >> apple[i];
        answer += apple[i] % student[i];
    }

    cout << answer << '\n';

    return 0;
}