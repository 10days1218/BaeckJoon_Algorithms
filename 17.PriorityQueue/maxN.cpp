//#2075
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n * n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);

        if (pq.size() > n)
            pq.pop();
    }

    cout << pq.top() << '\n';

    return 0;
}