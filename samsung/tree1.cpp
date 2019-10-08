//#16235
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[11][11];
int maps[11][11];
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
struct TREE
{
    int X;
    int Y;
    int AGE;
};

vector<TREE> trees;

void year()
{
    //사계절
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> maps[i][j];
            a[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tree.X = x, tree.Y = y, tree.AGE = z;
        trees.push_back(tree);
    }

    for (int i = 0; i < k; i++)
    {
        year();
    }

    //cout << trees.size() << '\n';

    return 0;
}