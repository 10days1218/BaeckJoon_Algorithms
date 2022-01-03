#include <bits/stdc++.h>
using namespace std;

int numbers[20];
int num, T, answer, sum;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T >> num;
    for (int i = 0; i < T; i++)
        cin >> numbers[i];

    for (int i = 1; i < (1 << T); i++)
    {
        sum = 0;
        for (int j = 0; j < T; j++)
        {
            if (i & (1 << j))
                sum += numbers[j];
        }

        if (sum == num)
            answer++;
    }

    cout << answer << '\n';

    return 0;
}