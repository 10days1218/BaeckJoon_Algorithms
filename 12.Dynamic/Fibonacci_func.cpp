//#1003
#include <bits/stdc++.h>
using namespace std;

vector<int> v(41, 0);

int f(int n)
{

    if (n <= 1)
        return v[n];

    else if (v[n] > 0)
        return v[n];

    return v[n] = f(n - 1) + f(n - 2);
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    v[0] = 1;
    v[1] = 1;

    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;

        if (tmp == 0)
            cout << "1 0\n";
        else if (tmp == 1)
            cout << "0 1\n";
        else
        {
            f(tmp);
            cout << v[tmp - 2] << " " << v[tmp - 1] << '\n';
        }
    }
    return 0;
}