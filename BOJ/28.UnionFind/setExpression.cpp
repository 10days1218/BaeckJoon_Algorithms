//https://www.acmicpc.net/problem/1717
#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1000001];

void Union(int a, int b);
int Find(int a);

int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) //같은 집합인지 확인
        {
            int x = Find(a), y = Find(b);
            if (x == y)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }

        else if (op == 0) //같은 집합으로 만들기
        {
            Union(a, b);
        }
    }
    return 0;
}

int Find(int a)
{
    if (a == parent[a])
        return a;
    else
    {
        int b = Find(parent[a]);
        parent[a] = b; //?
        return b;
    }
}

void Union(int a, int b)
{
    a = Find(a), b = Find(b);
    parent[b] = a;
}
