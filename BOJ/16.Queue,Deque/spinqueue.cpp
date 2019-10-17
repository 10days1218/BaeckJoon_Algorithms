//#1021
#include <bits/stdc++.h>
using namespace std;

int arr[51] = {0};
int main(void)
{
    int n, count, idx = 0;
    int left, right, answer = 0;
    int index;
    deque<int> dq;
    cin >> n >> count;

    for (int i = 0; i < count; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    while (1)
    {
        if (idx == count)
            break;

        for (deque<int>::size_type i = 0; i < dq.size(); i++)
        {
            if (dq[i] == arr[idx])
            {
                index = i;
            }
        }

        if (index == 0)
        {
            //cout << dq.front() << '\n';
            dq.pop_front();
            idx++;
            continue;
        }

        left = index;
        right = dq.size() - index;

        if (left < right)
        {
            for (int i = 0; i < left; i++)
            {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
            //cout << dq.front() << '\n';
            dq.pop_front();
            answer += left;
            idx++;
        }
        else
        {
            for (int i = 0; i < right; i++)
            {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
            //cout << dq.front() << '\n';
            dq.pop_front();
            answer += right;
            idx++;
        }
    }

    cout << answer << '\n';

    return 0;
}