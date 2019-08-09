//#1655
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, mid;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        if (maxHeap.empty())
            maxHeap.push(tmp);

        else if (maxHeap.top() < tmp)
            minHeap.push(tmp);
        else
            maxHeap.push(tmp);

        if (maxHeap.size() < minHeap.size())
            maxHeap.push(minHeap.top()), minHeap.pop();

        else if (maxHeap.size() > minHeap.size() + 1)
            minHeap.push(maxHeap.top()), maxHeap.pop();

        cout << maxHeap.top() << '\n';
    }
    return 0;
}