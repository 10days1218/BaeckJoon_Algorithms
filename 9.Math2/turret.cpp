//#1002
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int num = 0;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int x1, y1, x2, y2, r1, r2 = 0;
        double d = 0;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        if (x1 == x2 && y1 == y2)
        {
            if (r1 == r2)
                cout << "-1\n";
            else
                cout << "0\n";
        }

        else if (abs(r1 - r2) < d && r1 + r2 > d)
            cout << "2\n";

        else if (abs(r1 - r2) == d || r1 + r2 == d)
            cout << "1\n";

        else
            cout << "0\n";
    }

    return 0;
}