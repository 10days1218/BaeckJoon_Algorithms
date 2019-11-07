//https://www.acmicpc.net/problem/10798
#include <bits/stdc++.h>
using namespace std;

string str[5];
char s[5][15];
int main(void)
{
    int m = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> str[i];
    }

    fill_n(s[0], 5 * 15, ' ');

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            s[i][j] = str[i][j];
        }
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (s[j][i] == ' ')
                continue;
            cout << s[j][i];
        }
    }

    cout << '\n';
    return 0;
}
