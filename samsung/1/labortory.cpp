//14502
#include <bits/stdc++.h>
using namespace std;
#define MAX 8

int n, m, answer = 0;
int arr[MAX][MAX];
int copy_arr[MAX][MAX];
vector<pair<int, int>> virus;
int dir_X[4] = {1, -1, 0, 0};
int dir_Y[4] = {0, 0, 1, -1};

void bfsVirus()
{
    int afterWall[MAX][MAX] = {0};
    queue<pair<int, int>> q;

    copy(&copy_arr[0][0], &copy_arr[0][0] + MAX * MAX, &afterWall[0][0]);

    for (int i = 0; i < virus.size(); i++)
    {
        q.push(virus[i]);
    }

    while (!q.empty())
    {
        pair<int, int> start = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = start.first + dir_X[i];
            int nextY = start.second + dir_Y[i];
            if ((nextX >= 0 && nextX < n) && (nextY >= 0 && nextY < m) && afterWall[nextX][nextY] == 0)
            {
                pair<int, int> tmp = make_pair(nextX, nextY);
                q.push(tmp);
                afterWall[nextX][nextY] = 2;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (afterWall[i][j] == 0)
                count++;
        }
    }

    answer = max(answer, count);
}

void makeWall(int count)
{
    if (count == 3)
    {
        bfsVirus();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (copy_arr[i][j] == 0)
            {
                copy_arr[i][j] = 1;
                makeWall(count + 1);
                copy_arr[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                virus.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                copy(&arr[0][0], &arr[0][0] + MAX * MAX, &copy_arr[0][0]);
                copy_arr[i][j] = 1;
                makeWall(1);
                copy_arr[i][j] = 0;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}