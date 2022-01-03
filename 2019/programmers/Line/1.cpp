#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int m, c;
    vector<int> messages;
    vector<pair<int, int>> consumers;
    int time = 0, idx = 0, cnt = 0;
    cin >> m >> c;
    consumers.assign(c, {0, 0});
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        messages.push_back(tmp);
    }

    while (cnt < m)
    {
        time++;
        for (int i = 0; i < c; i++)
        {
            if (consumers[i].first + consumers[i].second == time)
            {
                consumers[i].second = 0;
                cnt++;
            }
            if (time - consumers[i].first > 100 && idx + 1 < m)
            {
                consumers[i].second = 0;
            }
            if (consumers[i].second == 0 && idx < m)
            {
                consumers[i].first = time;
                consumers[i].second = messages[idx];
                idx++;
            }
        }
        cout << consumers[0].second << " " << consumers[1].second << '\n';
    }

    cout << time << '\n';

    return 0;
}