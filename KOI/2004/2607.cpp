//https://www.acmicpc.net/problem/2607
#include <bits/stdc++.h>
using namespace std;

int n;
string str[101];
int characters[26];
int main(void)
{
    string testCase;
    int ans = 0, len = 0;

    cin >> n;
    cin >> testCase;

    for (int i = 0; i < testCase.size(); i++)
        characters[testCase[i] - 'A']++;

    for (int i = 0; i < n - 1; i++)
        cin >> str[i];

    for (int i = 0; i < n - 1; i++)
    {
        int tmp[26];
        int cnt1 = 0, cnt2 = 0;
        bool flag = true;
        fill(tmp, tmp + 26, 0);

        for (int j = 0; j < str[i].size(); j++)
            tmp[str[i][j] - 'A']++;

        for (int j = 0; j < 26; j++)
        {
            if (characters[j] != tmp[j])
            {
                if (characters[j] > tmp[j])
                    cnt1 += characters[j] - tmp[j];
                else
                    cnt2 += tmp[j] - characters[j];
            }

            if (cnt1 > 1 || cnt2 > 1)
                break;

            if (j == 25)
                ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}