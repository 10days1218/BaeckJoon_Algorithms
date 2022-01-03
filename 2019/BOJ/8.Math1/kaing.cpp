//#6064
#include <iostream>
using namespace std;

int lcm(int m, int n);

int main(void)
{
    int num = 0;
    int m, n, x, y;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> m >> n >> x >> y;
        int lcmN = lcm(m, n);
        while (x != y && x <= lcmN)
        {
            if (x < y)
                x += m;
            else
                y += n;
        }

        if (x != y)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << x << endl;
        }
    }

    return 0;
}

int lcm(int m, int n)
{
    int a = m, b = n, tmp;
    while (b)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return (m * n) / a;
}