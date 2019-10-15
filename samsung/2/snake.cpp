//#3190
#include <bits/stdc++.h>
using namespace std;

struct CMD
{
    int time;
    char dir;
};

struct POS
{
    int y;
    int x;
};

int n, k, l;
int maps[100][100];
CMD cmd[100];
POS head, tail;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(void)
{
    int t = 0;
    int d = 0;
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        y--, x--;
        maps[y][x] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> cmd[i].time >> cmd[i].dir;
    }

    queue<POS> q;
    head.y = 0, head.x = 0;
    maps[head.y][head.x] = 2;
    tail = head;
    int i = 0;

    while (1)
    {
        t++;
        head.y = head.y + dy[d], head.x = head.x + dx[d];
        if (head.y < 0 || head.y >= n || head.x < 0 || head.x >= n || maps[head.y][head.x] == 2)
            break;

        q.push(head);
        if (maps[head.y][head.x] == 0)
        {
            maps[tail.y][tail.x] = 0;
            tail = q.front();
            maps[tail.y][tail.x] = 2;
            q.pop();
        }
        maps[head.y][head.x] = 2;

        if (i < l && cmd[i].time == t)
        {
            if (cmd[i].dir == 'L')
            {
                d = d > 0 ? d - 1 : 3;
            }
            else
            {
                d = d < 3 ? d + 1 : 0;
            }
            i++;
        }
    }

    cout << t << '\n';

    return 0;
}