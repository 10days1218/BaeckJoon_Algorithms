//#1026
#include <bits/stdc++.h>
using namespace std;

int A[51];
int B[51];

bool com(int a, int b)
{
    return a > b;
}
int main(void)
{
    int n;
    int answer = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        cin >> B[i];

    sort(B, B + n);
    sort(A, A + n, com);

    for (int i = 0; i < n; i++)
        answer += A[i] * B[i];

    cout << answer << '\n';

    return 0;
}