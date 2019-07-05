//#1929
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int M, N = 0;
    int answer = 0;
    int count = 0;
    int mini = 0;
    cin >> M >> N;
    vector<bool> v(N + 1, true);
    v[0] = v[1] = false;

    for (int i = 2; i < sqrt(N); i++)
    {
        if (v[i])
        {
            for (int j = i * 2; j <= N; j += i)
                v[j] = false;
        }
    }

    for (int i = M; i < N + 1; i++)
    {
        if (v[i] == true)
            cout << i << '\n'
    }

    return 0;
}