//#16235
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[11][11];
int maps[11][11];
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
vector<int> trees[11][11];
struct TREE
{
    int X;
    int Y;
    int AGE;
};

TREE tree;
int Year = 0;
void year()
{
    vector<tree> live;
    vector<tree> dead;
    vector<tree> five;
    //봄
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if (trees[y][x].size() > 0)
            {
                sort(trees[y][x].begin(), trees[y][x].end());
                for (int j = 0; j < trees[y][x].size(); j++)
                {
                    if (a[y][x] >= trees[y][x][j])
                    {
                        a[y][x] -= trees[y][x][j];
                        trees[y][x][j]++;
                        tree = ;
                        live.push_back()
                    }
                    else
                    {
                        trees[y][x][j] *= (-1);
                    }
                }
            }
        }
    }

    //여름
    int cnt = 0;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if (trees[y][x].size() > 0)
            {
                sort(trees[y][x].begin(), trees[y][x].end());
                for (int k = 0; k < trees[y][x].size(); k++)
                {
                    if (trees[y][x][k] < 0)
                    {
                        cnt++;
                        a[y][x] += (trees[y][x][k] * (-1)) / 2;
                    }
                }

                reverse(trees[x][y].begin(), trees[x][y].end());
                for (int j = 0; j < cnt; j++)
                    trees[y][x].pop_back();
            }
        }
    }

    //가을
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            if (trees[y][x].size() > 0)
            {
                for (int j = 0; j < trees[y][x].size(); j++)
                {
                    if (trees[y][x][j] % 5 == 0)
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            int r = y + dir[k][0];
                            int c = x + dir[k][1];
                            if (r >= 1 && r <= n && c >= 1 && c <= n)
                            {
                                trees[r][c].push_back(1);
                            }
                        }
                    }
                }
            }
        }
    }

    //겨울
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            a[r][c] += maps[r][c];
        }
    }
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
        trees[x][y].push_back(z);
    }

    for (int i = 0; i < k; i++)
    {
        year();
    }

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            answer += (int)trees[r][c].size();
        }
    }

    cout << answer << '\n';

    return 0;
}