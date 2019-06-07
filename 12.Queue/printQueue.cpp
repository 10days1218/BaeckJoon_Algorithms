//#1966
#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    int num = 0;
    int n, m;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            q.push({j, tmp});
            pq.push(tmp);
        }
        whie(!q.empty())
        {
            int idx = q.front().first();
            int val = q.front().second();
            q.pop();
            if (pq.top() == val)
            {
                pq.pop();
                count++;
                if (idx == m)
                {
                    cout << count << endl;
                    break;
                }
            }
            else
            {
                q.push(idx, val);
            }
        }
    }

    return 0;
}