#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    vector<int> answer;
    vector<pair<int, int>> v;
    answer.assign(1, 0);
    int time = 0, idx = 0, cnt = 0;
    bool check = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v.push_back({t1, t2});
    }

    sort(v.begin(), v.end());

    while (cnt < v.size())
    {
        for (int i = 0; i < answer.size(); i++)
        {
            if (answer[i] != 0 && answer[i] == time)
            {
                answer[i] = 0;
                cnt++;
            }
            if (answer[i] == 0 && time == v[idx].first)
            {
                answer[i] = v[idx].second;
                idx++;
                check = true;
            }
        }
        if (check == false && v[idx].first == time)
        {
            answer.push_back(v[idx].second);
            idx++;
        }
        check = false;
        time++;
    }

    cout << answer.size() << '\n';
    return 0;
}