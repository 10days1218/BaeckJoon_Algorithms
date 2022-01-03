//https://www.acmicpc.net/problem/5014
#include <bits/stdc++.h>
using namespace std;

bool check[1000000];
int main(void)
{
    // f: 건물 총 층, s: 강호의 위치, g: 스타트링크, u:위, d:아래
    int f, s, g, u, d;
    int answer = -1;
    cin >> f >> s >> g >> u >> d;

    const int upDown[2] = {u, d * (-1)};
    queue<pair<int, int>> q;
    q.push({s, 0});
    check[s] = true;

    while (!q.empty())
    {
        int current = q.front().first;
        int count = q.front().second;
        q.pop();
        // cout << current << '\n';

        if (current == g)
        {
            answer = count;
            break;
        }

        for (int dir = 0; dir < 2; dir++)
        {
            int nFloor = current + upDown[dir];

            if (nFloor > f || nFloor < 1 || check[nFloor])
                continue;

            q.push({nFloor, count + 1});
            check[nFloor] = true;
        }
    }

    if (answer == -1)
        cout << "use the stairs\n";
    
    else
        cout << answer << '\n';
    
    return 0;
}