//#1992
#include <bits/stdc++.h>
using namespace std;

string arr[65];
//string out = "";

void quad(int x, int y, int l)
{
    char first = arr[x][y];
    bool check = true;
    //cout << "(";
    for (int i = x; i < x + l; i++)
    {
        for (int j = y; j < y + l; j++)
        {
            if (arr[i][j] != first)
            {
                cout << "(";
                quad(x, y, l / 2);
                quad(x, y + l / 2, l / 2);
                quad(x + l / 2, y, l / 2);
                quad(x + l / 2, y + l / 2, l / 2);
                cout << ")";
                return;
            }
        }
    }

    if (first == '1')
        cout << "1";
    else
        cout << "0";

    //
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quad(0, 0, n);

    return 0;
}
