//#14891
#include <bits/stdc++.h>
using namespace std;

int k;
string gear[4];
struct GEAR
{
    int N;
    int ROTATE;
};

void rotate(int n, int r)
{
    if (r == 1)
    {
        char tmp = gear[n][7];
        string str;
        str += tmp;
        str += gear[n].substr(0, 7);
        gear[n] = str;
    }
    else
    {
        char tmp = gear[n][0];
        string str = gear[n].substr(1, 7);
        str += tmp;
        gear[n] = str;
    }
}

int main(void)
{
    int answer = 0;
    GEAR tmp;
    for (int i = 0; i < 4; i++)
    {
        cin >> gear[i];
    }

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        bool check[] = {false, false, false, false};
        queue<GEAR> q;
        cin >> tmp.N >> tmp.ROTATE;
        tmp.N--;
        q.push(tmp);
        check[tmp.N] = true;

        while (!q.empty())
        {
            int n = q.front().N, r = q.front().ROTATE;
            q.pop();
            int left = n - 1, right = n + 1;

            if (left >= 0 && left < 4 && !check[left])
            {
                if (gear[left][2] != gear[n][6])
                {
                    tmp.N = left, tmp.ROTATE = r * (-1);
                    q.push(tmp);
                    check[left] = true;
                }
            }

            if (right >= 0 && right < 4 && !check[right])
            {
                if (gear[n][2] != gear[right][6])
                {
                    tmp.N = right, tmp.ROTATE = r * (-1);
                    q.push(tmp);
                    check[right] = true;
                }
            }
            rotate(n, r);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        answer += gear[i][0] == '0' ? 0 : pow(2, i);
    }

    cout << answer << '\n';
    return 0;
}