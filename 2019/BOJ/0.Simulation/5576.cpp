//https://www.acmicpc.net/problem/5576
#include <bits/stdc++.h>
using namespace std;

int w[10];
int k[10];
int main(void)
{
    for (int i = 0; i < 10; i++)
        cin >> w[i];

    for (int j = 0; j < 10; j++)
        cin >> k[j];

    sort(w, w + 10);
    sort(k, k + 10);

    int wScore = w[9] + w[8] + w[7];
    int kScore = k[9] + k[8] + k[7];

    cout << wScore << " " << kScore << '\n';
    return 0;
}