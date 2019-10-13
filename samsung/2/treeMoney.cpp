//#16235
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int maps[10][10];
int add[10][10];
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct TREE
{
    int y;
    int x;
    int age;
};

queue<TREE> new_tree;
queue<TREE> trees;

int main(void)
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> add[i][j];
            maps[i][j] = 5;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int r, c, a;
        cin >> r >> c >> a;
        tree.y = r, tree.x = c, tree.age = a;
    }

    while (k--)
    {
        queue<TREE> dead_tree, five;

        for (int i = 0; i < new_tree.size(); i++)
        {
            TREE t = new_tree.front();
            new_tree.pop();
            if (maps[i][j] >= t.age)
            {
                maps[i][j] -= t.age;
                t.age++;
                trees.push(t);
                if (t.age % 5 == 0)
                    five.push(t);
            }
            else
            {
                dead_tree(t);
            }
        }

        new_tree.clear();

        for (int i = 0; i < trees.size(); i++)
        {
            TREE t = trees.front();
            trees.pop();
            if (maps[i][j] >= t.age)
            {
                maps[i][j] -= t.age;
                t.age++;
                trees.push(t);
                if (t.age % 5 == 0)
                    five.push(t);
            }
            else
            {
                dead_tree(t);
            }
        }

        for (int i = 0; i < five.size(); i++)
        {
            TREE t = five.front();
            five.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int ny = t.y + dy[dir], nx = t.x + dx[dir];
                if (ny < 0 || ny >= n || nx < 0 || nx >= 0)
                    continue;
            }
        }
    }

    return 0;
}