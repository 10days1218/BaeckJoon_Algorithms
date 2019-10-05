//#2960
#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int answer[1001];
int main(void)
{
    int n, k;
    int cnt = 0;
    cin >> n >> k;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i < sqrt(n); i++)
    {
        if (cnt == k)
            break;

        if (arr[i] == 0)
        {
            continue;
        }
        for (int j = i * 2; j <= n; j += i)
        {
            arr[j] = 0;
            answer[cnt++] = j;
        }
    }

    cout << answer[k - 1] << '\n';
    return 0;
}