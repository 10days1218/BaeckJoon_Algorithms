//#4153
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    while (1)
    {
        int n1, n2, n3 = 0;
        cin >> n1 >> n2 >> n3;
        if (n1 == 0 && n2 == 0 && n3 == 0)
            break;
        if (n1 * n1 + n2 * n2 == n3 * n3 || n1 * n1 + n3 * n3 == n2 * n2 || n2 * n2 + n3 * n3 == n1 * n1)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }

    return 0;
}