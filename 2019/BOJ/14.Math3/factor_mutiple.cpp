//#5086
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<pair<int, int>> v;
    vector<pair<int, int>>::iterator i;

    while (1)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        v.push_back(pair<int, int>(n, m));
    }

    for (i = v.begin(); i < v.end(); i++)
    {
        if (i->first % i->second == 0 && i->first > i->second)
            cout << "multiple\n";
        else if (i->second % i->first == 0 && i->second > i->first)
            cout << "factor\n";
        else
            cout << "neither\n";
    }

    return 0;
}