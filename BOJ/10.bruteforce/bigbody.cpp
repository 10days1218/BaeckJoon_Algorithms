//#7568
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int num;
    int idx = 0;
    vector<pair<int, int>> v;
    vector<pair<int, int>>::iterator i;
    vector<pair<int, int>>::iterator j;

    cin >> num;
    vector<int> answer(num, 1);
    for (int i = 0; i < num; i++)
    {
        int x, y = 0;
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }

    for (i = v.begin(); i != v.end(); i++)
    {
        for (j = v.begin(); j != v.end(); j++)
        {
            if (i->first < j->first && i->second < j->second)
            {
                answer[idx]++;
            }
        }
        idx++;
    }

    for (int i = 0; i < num; i++)
        cout << answer[i] << ' ';
    cout << '\n';

    return 0;
}