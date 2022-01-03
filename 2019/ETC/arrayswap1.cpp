//16926
#include <bits/stdc++.h>
using namespace std;

int arr[301][301];
int n, m, r, cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void rotate()
{
    for (int i = 0; i < cnt; i++)
    {
        int temp = arr[i][i];
        int index = 0;
        int lx = i, ly = i;
        while (index < 4)
        {
            int nx = lx + dx[index];
            int ny = ly + dy[index];

            if (nx >= i && ny >= i && nx < n - i && ny < m - i)
            {
                arr[lx][ly] = arr[nx][ny];
                lx = nx;
                ly = ny;
            }
            else
            {
                index++;
            }
        }
        arr[i + 1][i] = temp;
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    cnt = min(n, m) / 2;

    for (int i = 0; i < r; i++)
        rotate();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}