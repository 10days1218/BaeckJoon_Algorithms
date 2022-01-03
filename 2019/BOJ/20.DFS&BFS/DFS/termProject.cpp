//https://www.acmicpc.net/problem/9466
#include <bits/stdc++.h>
using namespace std;

int student[100001];
bool visited[100001];
bool check[100001];
int cnt;

void cycle(int current);
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++)
            cin >> student[j];

        for (int k = 1; k <= m; k++)
        {
            if (!visited[k])
                cycle(k);
        }

        cout << m - cnt << '\n';
        fill(visited, visited + 100001, false);
        fill(check, check + 100001, false);
        fill(student, student + 100001, 0);
        cnt = 0;
    }

    return 0;
}

void cycle(int current)
{
    visited[current] = true;
    int next = student[current];

    if (!visited[next])
        cycle(next);

    else
    {
        if (!check[next])
        {
            for (int i = next; current != i; i = student[i])
                cnt++;
            cnt++;
        }
    }
    check[current] = true;
}