//#10773
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 0;
    int answer = 0;
    stack<int> s;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
            s.pop();
        else
            s.push(tmp);
    }

    while (!s.empty())
    {
        answer += s.top();
        s.pop();
    }

    cout << answer << '\n';
    return 0;
}