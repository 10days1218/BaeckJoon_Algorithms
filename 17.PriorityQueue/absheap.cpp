//#11286
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
        {
            if (pq.size() == 0)
                cout << '0' << '\n';
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }

        else
        {
            pair<int, int> p_tmp(abs(tmp), tmp);
            pq.push(p_tmp);
        }
    }
    return 0;
}
