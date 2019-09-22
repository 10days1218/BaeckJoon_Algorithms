//#12100
#include <bits/stdc++.h>
using namespace std;

int n;
int maps[21][21];
int dir_X[4] = {1, 0, -1, 0};
int dir_Y[4] = {0, 1, 0, -1};
vector<int> v;
int temp[21][21];
void dfs(int count)
{
    if (count == 5)
    {
        copy(&maps[0][0], &maps[0][0] + n * n, temp);
        for (int i = 0; i < 5; i++)
        {
            if (v[i] == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0 j < n; j++)
                    {
                        ;
                    }
                }
            }
            if (v[i] == 1)
            {
                ;
            }
            if (v[i] == 2)
            {
                ;
            }
            if (v[i] == 3)
            {
                ;
            }
        }
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        v.push_back(i);
        dfs(count + 1);
        v.pop();
    }
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maps[i][j];

    dfs(0);
    return 0;
}