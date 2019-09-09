//#11050
#include <bits/stdc++.h>
using namespace std;

int pascal[1001][1001] = {0};

void P(int n)
{
    pascal[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pascal[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % 10007;
        }
    }
}
int main(void)
{
    int n, k = 0;
    cin >> n >> k;
    P(n);
    cout << pascal[n][k] << '\n';
    return 0;
}