#include <bits/stdc++.h>

using namespace std;
int visited[1 << 17]; // 비트마스킹,상태x를 방문했는가?
int l[20], r[20], val[20];
int n;
int answer;

void dfs(int state)
{
    // 이미 방문한 경로인 경우
    if (visited[state])
        return;

    visited[state] = 1;

    int wolf = 0, num = 0;

    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i)) // 방문하지 않은 경로인 경우
        {
            num++;
            wolf += val[i];
        }
    }

    if (2 * wolf >= num)
        return;

    answer = max(answer, num - wolf);

    for (int i = 0; i < n; i++)
    {
        if (!(state & (1 << i)))
            continue;

        if (l[i] != -1)
            dfs(state | 1 << l[i]);

        if (r[i] != -1)
            dfs(state | 1 << r[i]);
    }
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    n = info.size();
    fill(l, l + n, -1);
    fill(r, r + n, -1);

    for (int i = 0; i < n; i++)
        val[i] = info[i];

    for (int i = 0; i < n - 1; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        if (l[a] == -1)
            l[a] = b;
        else
            r[a] = b;
    }

    dfs(1);

    return answer;
}

int main(void)
{
    vector<int> info = {0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1};
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}};

    solution(info, edges);
    cout << answer << "\n";
    return 0;
}