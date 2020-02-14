//https://www.acmicpc.net/problem/17822
#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int gear[51][50];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

void turn(int x, int d, int k);
int removeNumber();
void addNumber();
int main(void)
{
    int answer = 0;
    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            cin >> gear[i][j];

    for (int tc = 0; tc < T; tc++)
    {
        int x, d, k;
        cin >> x >> d >> k;
        turn(x, d, k);
        int count = removeNumber();

        if (count == 0)
            addNumber(); //double...
    }

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            answer += gear[i][j];

    cout << answer << '\n';
    return 0;
}

void turn(int x, int d, int k)
{
    for (int tc = 0; tc < k; tc++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (i % x != 0)
                continue;

            if (d == 0) // 시계
            {
                int tmp = gear[i][M - 1];
                for (int j = M - 1; j > 0; j--)
                    gear[i][j] = gear[i][j - 1];

                gear[i][0] = tmp;
            }

            else // 반시계
            {
                int tmp = gear[i][0];
                for (int j = 0; j < M - 1; j++)
                    gear[i][j] = gear[i][j + 1];

                gear[i][M - 1] = tmp;
            }
        }
    }
}

int removeNumber()
{
    int count = 0;
    queue<pair<int, int>> Q;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            queue<pair<int, int>> q;
            int cnt = 0;
            int number = gear[i][j];

            if (number == 0)
                continue;

            for (int dir = 0; dir < 4; dir++)
            {
                int nY = i + dy[dir], nX = j + dx[dir];
                if (nY < 1 || nY > N)
                    continue;

                else if (nX < 0)
                    nX = M - 1;
                else if (nX > M - 1)
                    nX = 0;

                if (number == gear[nY][nX])
                {
                    q.push({nY, nX});
                    count++;
                }
            }

            if (q.size() > 0)
                q.push({i, j});

            while (!q.empty())
            {
                Q.push(q.front());
                q.pop();
            }
        }
    }

    while (!Q.empty())
    {
        int y = Q.front().first, x = Q.front().second;
        gear[y][x] = 0;
        Q.pop();
    }

    return count;
}

void addNumber()
{
    int sum = 0;
    int count = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (gear[i][j] != 0)
            {
                sum += gear[i][j];
                count++;
            }
        }
    }

    double aver = (double)sum / (double)count;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (gear[i][j] == 0)
                continue;

            if (aver < (double)gear[i][j])
                gear[i][j] -= 1;

            else if (aver > (double)gear[i][j])
                gear[i][j] += 1;
        }
    }
}