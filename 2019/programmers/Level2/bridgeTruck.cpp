// #include <string>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int i = 0, cnt = 0, w = 0;
    queue<pair<int, int>> q;

    while (1)
    {
        answer++;
        if (!q.empty() && answer - q.front().second == bridge_length)
        {
            w -= q.front().first;
            q.pop();
            cnt++;
        }

        if (w + truck_weights[i] <= weight && q.size() < bridge_length && i < truck_weights.size())
        {
            w += truck_weights[i];
            q.push(make_pair(truck_weights[i], answer));
            i++;
        }

        if (cnt == truck_weights.size())
            break;
    }
    cout << answer;
    return answer;
}

int main(void)
{
    int bridge = 2, w = 10;
    vector<int> truck = {7, 4, 5, 6};
    solution(bridge, w, truck);
}