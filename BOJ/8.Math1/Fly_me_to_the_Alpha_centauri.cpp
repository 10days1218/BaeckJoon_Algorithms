//#1011
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int num = 0;
    cin >> num;
    int count = 0;
    int *x = new int[num];
    int *y = new int[num];
    vector<int> v(1000, 0);
    int loc = 3;
    int loop = 2;
    int val = 3;

    for (int i = 0; i < num; i++)
        cin >> x[i] >> y[i];

    v[1] = 1;
    v[2] = 2;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < loop; k++)
            {
                v[loc++] = val;
            }
            val++;
            for (int l = 0; l < loop; l++)
            {
                v[loc++] = val;
            }
            val++;
            loop++;
        }
        cout << v[y[i] - x[i]] << '\n';
        loc = 3;
        loop = 2;
        val = 3;
        v.assign(1000, 0);
    }
    return 0;
}
