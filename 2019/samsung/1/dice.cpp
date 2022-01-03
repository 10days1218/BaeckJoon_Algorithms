//#14499
#include <bits/stdc++.h>
using namespace std;
struct POS
{
    int Y;
    int X;
};

int n, m, x, y, k;
int maps[20][20];
int cmd[1000];
int dice[4][3];

POS top;
POS bottom;
POS east;
POS west;
POS front;
POS back;

POS cur;

int main(void)
{
    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < k; i++)
        cin >> cmd[i];

    top.Y = 1, top.X = 1, bottom.Y = 3, bottom.X = 1;
    east.Y = 1, east.X = 2, west.Y = 1, west.X = 0;
    front.Y = 2, front.X = 1, back.Y = 0, back.X = 1;
    cur.Y = y, cur.X = x;

    for (int i = 0; i < k; i++)
    {
        //동
        if (cmd[i] == 1)
        {
            if (cur.X + 1 >= m)
                continue;

            POS tmp = top;
            top.Y = west.Y, top.X = west.X;
            west.Y = bottom.Y, west.X = bottom.X;
            bottom.Y = east.Y, bottom.X = east.X;
            east.Y = tmp.Y, east.X = tmp.X;

            cur.X++;
        }

        //서
        if (cmd[i] == 2)
        {
            if (cur.X - 1 < 0)
                continue;

            POS tmp = top;
            top.Y = east.Y, top.X = east.X;
            east.Y = bottom.Y, east.X = bottom.X;
            bottom.Y = west.Y, bottom.X = west.X;
            west.Y = tmp.Y, west.X = tmp.X;

            cur.X--;
        }

        //북
        if (cmd[i] == 3)
        {
            if (cur.Y - 1 < 0)
                continue;

            POS tmp = top;
            top.Y = front.Y, top.X = front.X;
            front.Y = bottom.Y, front.X = bottom.X;
            bottom.Y = back.Y, bottom.X = back.X;
            back.Y = tmp.Y, back.X = tmp.X;

            cur.Y--;
        }

        //남
        if (cmd[i] == 4)
        {
            if (cur.Y + 1 >= n)
                continue;

            POS tmp;
            tmp = top;
            top.Y = back.Y, top.X = back.X;
            back.Y = bottom.Y, back.X = bottom.X;
            bottom.Y = front.Y, bottom.X = front.X;
            front.Y = tmp.Y, front.X = tmp.X;

            cur.Y++;
        }

        if (maps[cur.Y][cur.X] != 0)
        {
            dice[bottom.Y][bottom.X] = maps[cur.Y][cur.X];
            maps[cur.Y][cur.X] = 0;
        }

        else if (maps[cur.Y][cur.X] == 0)
        {
            maps[cur.Y][cur.X] = dice[bottom.Y][bottom.X];
        }

        cout << dice[top.Y][top.X] << '\n';
    }
    return 0;
}