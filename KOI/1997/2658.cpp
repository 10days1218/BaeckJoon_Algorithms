//https://www.acmicpc.net/problem/2658
#include <bits/stdc++.h>
using namespace std;

struct POS
{
    int y;
    int x;
};
char maps[10][10];

int main(void)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> maps[i][j];

    // bool flag = false;
    vector<POS> ans;
    int area = 0;
    int row = 0, col = 0;
    int rX1, rY1, rX2, rY2, cX1, cY1, cX2, cY2;

    //가로에서 가장 긴 길이
    for (int i = 0; i < 10; i++)
    {
        int cnt = 0, tmpY, tmpX;
        for (int j = 0; j < 10; j++)
        {
            if (maps[i][j] == '1')
            {
                area++;
                if (cnt == 0)
                    tmpY = i, tmpX = j;

                cnt++;
            }
        }
        if (cnt > row)
            row = cnt, rY1 = tmpY, rX1 = tmpX;
    }

    rY2 = rY1, rX2 = rX1 + row - 1;

    //세로에서 가장 긴 길이
    for (int i = 0; i < 10; i++)
    {
        int cnt = 0, tmpY, tmpX;
        for (int j = 0; j < 10; j++)
        {
            if (maps[j][i] == '1')
            {
                if (cnt == 0)
                    tmpY = j, tmpX = i;

                cnt++;
            }
        }
        if (cnt > col)
            col = cnt, cY1 = tmpY, cX1 = tmpX;
    }

    cY2 = cY1 + col - 1, cX2 = cX1;

    if (row >= col)
    {
        if ((rX1 + rX2) / 2 == cX2 && rY1 == cY2)
        {
            int check = row * col / 2;
            if (check == area)
            {
                ans.push_back({rY1, rX1});
                ans.push_back({rY2, rX2});
                ans.push_back({cY1, cY2});
            }
        }
    }

    else
    {
        if ((cY1 + cY2) / 2 == rY2 && cX1 == rX2)
        {
            int check = row * col / 2;
            if (check == area)
            {
                ans.push_back({cY1, cX1});
                ans.push_back({cY2, cX2});
                ans.push_back({rY1, rY2});
            }
        }
    }

    if (ans.size() == 0)
        cout << "0\n";

    else
    {
        for (int i = 0; i < 3; i++)
            cout << ans[i].y << " " << ans[i].x << '\n';
    }

    return 0;
}