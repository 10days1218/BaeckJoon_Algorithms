//#16235
#include <bits/stdc++.h>
using namespace std;

struct TREE
{
    int X, Y, AGE;
};

bool cmp(TREE a, TREE b)
{
    return (a.AGE > b.AGE);
}

int n, m, k;
queue<TREE> tree[2];
TREE init_tree[100];

int maps[11][11], add[11][11];
const int dy[] = {-1, -1, -1, 0, 0, +1, +1, +1};
const int dx[] = {-1, 0, +1, -1, +1, -1, 0, +1};

int main(void)
{
    int cur = 0, next;
    cin >> n >> m >> k;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            cin >> add[y][x];
            maps[y][x] = 5;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> init_tree[i].Y >> init_tree[i].X >> init_tree[i].AGE;
    }

    sort(init_tree, init_tree + m, cmp);

    for (int i = 0; i < m; i++)
    {
        tree[cur].push(init_tree[i]);
    }

    queue<TREE> new_tree;
    for (int i = 0; i < k; i++)
    {
        next = (cur + 1) % 2;
        queue<TREE> dead_tree;
        queue<TREE> birth_of_child_tree;

        while (!new_tree.empty())
        {
            TREE cur_tree = new_tree.front();
            new_tree.pop();

            if (maps[cur_tree.Y][cur_tree.X] >= cur_tree.AGE)
            {
                maps[cur_tree.Y][cur_tree.X] -= cur_tree.AGE;
                cur_tree.AGE++;
                tree[next].push(cur_tree);
            }
            else
            {
                dead_tree.push(cur_tree);
            }
        }

        while (!tree[cur].empty())
        {
            TREE cur_tree = tree[cur].front();
            tree[cur].pop();

            if (maps[cur_tree.Y][cur_tree.X] >= cur_tree.AGE)
            {
                maps[cur_tree.Y][cur_tree.X] -= cur_tree.AGE;
                ++cur_tree.AGE;
                tree[next].push(cur_tree);

                if (cur_tree.AGE % 5 == 0)
                    birth_of_child_tree.push(cur_tree);
            }
            else
            {
                dead_tree.push(cur_tree);
            }
        }

        while (!dead_tree.empty())
        {
            TREE cur_tree = dead_tree.front();
            dead_tree.pop();
            maps[cur_tree.Y][cur_tree.X] += (cur_tree.AGE / 2);
        }

        while (!new_tree.empty())
        {
            new_tree.pop();
        }

        while (!birth_of_child_tree.empty())
        {
            TREE cur_tree = birth_of_child_tree.front();
            birth_of_child_tree.pop();
            if ((cur_tree.AGE % 5) == 0)
            {
                for (int dir = 0; dir < 8; dir++)
                {
                    TREE next_tree;
                    next_tree.Y = cur_tree.Y + dy[dir];
                    next_tree.X = cur_tree.X + dx[dir];
                    next_tree.AGE = 1;

                    if (next_tree.Y <= 0 || next_tree.Y > n || next_tree.X <= 0 || next_tree.X > n)
                        continue;

                    new_tree.push(next_tree);
                }
            }
        }

        for (int y = 1; y <= n; y++)
        {
            for (int x = 1; x <= n; x++)
            {
                maps[y][x] += add[y][x];
            }
        }
        cur = next;
    }

    cout << (int)tree[next].size() + new_tree.size()
         << '\n';
    return 0;
}