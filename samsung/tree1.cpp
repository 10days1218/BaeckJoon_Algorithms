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

TREE tree;
vector<TREE> trees;

bool cmp(const TREE &a, const TREE &b)
{
    if (a.X == b.X && a.Y == b.Y)
    {
        return a.AGE < b.AGE;
    }
    else
    {
        if (a.X == b.X)
        {
            return a.Y < b.Y;
        }
        else
        {
            return a.X < b.X;
        }
    }
}

void year()
{
    //사계절
    vector<TREE> dead;
    vector<TREE> live;
    vector<TREE> five;
    for (int i = 0; i < 4; i++)
    {
        sort(trees.begin(), trees.end(), cmp);
        //봄
        if (i == 0)
        {
            for (int j = 0; j < trees.size(); j++)
            {
                int r, c, age;
                r = trees[j].X;
                c = trees[j].Y;
                age = trees[j].AGE;

                if (a[r][c] >= age)
                {
                    a[r][c] -= age;
                    age++;
                    trees[j].AGE = age;
                    live.push_back(trees[j]);
                    if (age % 5 == 0)
                        five.push_back(trees[j]);
                }
                else
                {
                    dead.push_back(trees[j]);
                }
            }
        }

        //여름
        if (i == 1)
        {
            for (int j = 0; j < dead.size(); j++)
            {
                int r = dead[j].X;
                int c = dead[j].Y;
                int age = dead[j].AGE;
                a[r][c] += age / 2;
            }
        }

        //가을
        if (i == 2)
        {
            for (int j = 0; j < five.size(); j++)
            {
                int r = five[j].X;
                int c = five[j].Y;
                int age = five[j].AGE;
                if (age % 5 == 0)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (r + dir[k][0] >= 0 && r + dir[k][0] <= n && c + dir[k][1] >= 0 && c + dir[k][1] <= n)
                        {
                            tree.X = r + dir[k][0];
                            tree.Y = c + dir[k][1];
                            tree.AGE = 1;
                            live.push_back(tree);
                        }
                    }
                }
            }
        }

        //겨울
        if (i == 3)
        {
            for (int r = 1; r <= n; r++)
            {
                for (int c = 1; c <= n; c++)
                {
                    a[r][c] += maps[r][c];
                }
            }
        }
    }
    trees.clear();
    trees.resize((int)live.size());
    copy(live.begin(), live.end(), trees.begin());
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

    cout << trees.size() << '\n';

    return 0;
}