//https://www.acmicpc.net/problem/14864
#include <bits/stdc++.h>
using namespace std;

int student[100001];
bool check[100001];
int n, m;

void init();
int main(void)
{
    bool flag = false;
    cin >> n >> m;

    init();

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        student[a] += 1, student[b] -= 1;
    }

    for (int i = 1; i <= n; i++)
    {
        int j = student[i];

        if (j <= 0 || j > n)
        {
            flag = true;
            break;
        }

        else if (!check[j])
        {
            check[j] = true;
            continue;
        }
        else if (check[j])
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        for (int i = 1; i <= n; i++)
            cout << student[i] << " ";
        cout << '\n';
    }

    else
        cout << "-1\n";

    return 0;
}

void init()
{
    for (int i = 1; i <= n; i++)
        student[i] = i;
}
