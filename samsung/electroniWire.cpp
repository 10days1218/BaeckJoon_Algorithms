//#2565
#include <bits/stdc++.h>
using namespace std;

vector<pair<int>> wire;
int n;
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        wire.push_back({a, b});
    }

    sort(wire, begin(), wire.end());

    return 0;
}