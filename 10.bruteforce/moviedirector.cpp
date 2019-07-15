//#1436
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N = 0;
    int num = 0;
    string s;
    cin >> N;

    while (N > 0)
    {
        num++;
        s = to_string(num);
        if (s.find("666") != string::npos)
        {
            N--;
        }
    }

    cout << num << '\n';

    return 0;
}