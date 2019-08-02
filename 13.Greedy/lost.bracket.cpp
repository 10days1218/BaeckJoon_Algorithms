//#1541
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string str, temp = "";
    int len, ans = 0;
    bool m = false;
    cin >> str;
    len = str.size();

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            if (m == false)
                ans += stoi(temp);

            else
                ans -= stoi(temp);

            temp = "";

            if (str[i] == '-')
                m = true;

            continue;
        }
        else
            temp += str[i];
    }

    cout << ans << '\n';
    return 0;
}