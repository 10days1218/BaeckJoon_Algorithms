//#17298
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    stack<int> s;
    vector<int> answer(n, -1);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    s.push(1e9 + 7);

    for (int i = n - 1; i >= 0; i--)
    {
        while (v[i] >= s.top())
            s.pop();

        if (s.top() >= 1e9)
            answer[i] = -1;
        else
            answer[i] = s.top();
        s.push(v[i]);
    }

    for (int i = 0; i < n; i++)
        cout << answer[i] << ' ';

    return 0;
}