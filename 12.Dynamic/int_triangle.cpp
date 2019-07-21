//#1932
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 0;
    int index = 0;
    cin >> n;
    vector<int> v(n * (n + 1) / 2);
    vector<int> v_max(n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> v[index++];
        }
    }

    // for (int i = 0; i < v_max.size(); i++)
    //     cout << v_max[i] << ' ';

    // cout << '\n';

    v_max[0] = v[0];
    index = 1;

    for (int i = 1; i <= n; i++)
    {
        int tmp = v_max[i];
        for (int j = 0; j < i; j++)
        {
            int tmp2 = tmp + v[index++];
            v_max[i] = max(v_max[i], tmp2);
        }
    }

    for (int i = 0; i < v_max.size(); i++)
        cout << v_max[i] << ' ';

    cout << '\n';

    cout << v_max[index - 1] << '\n';

    return 0;
}