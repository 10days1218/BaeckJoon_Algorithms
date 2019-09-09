//#1225 암호 생성기
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int k = 0;
    int l = 1;
    for (int i = 0; i < 10; i++)
    {
        int n;
        vector<int> v(8);

        cin >> n;
        for (int j = 0; j < 8; j++)
            cin >> v[j];

        while (v[7] > 0)
        {
            v[0] -= l;
            l++;
            if (l == 6)
                l = 1;

            if (v[0] < 0)
                v[0] = 0;
            v.push_back(v[0]);
            v.erase(v.begin());
        }
        l = 1;

        cout << '#' << n << ' ';
        for (int k = 0; k < 8; k++)
            cout << v[k] << ' ';
        cout << '\n';
    }

    return 0;
}