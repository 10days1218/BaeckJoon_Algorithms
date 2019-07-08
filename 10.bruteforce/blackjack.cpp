//#2798
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, M, m = 0;
    int total = 0;
    vector<int> v;

    cin >> N >> M;
    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                total = v[i] + v[j] + v[k];
                if (total <= M)
                    m = max(total, m);
            }
        }
    }

    cout << m << '\n';
    return 0;
}