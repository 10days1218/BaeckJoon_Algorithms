//#17281
#include <bits/stdc++.h>
using namespace std;

int n;
int a[51][10];
vector<int> seq(9);
int atBat[3];
int ans;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 2; i <= 9; i++)
        seq[i - 1] = i;

    do
    {
        for (int i = 2; i < 9; i++)
            cout << seq[i] << " ";
        cout << '\n';
    } while (next_permutation(seq.begin(), seq.end()));

    return 0;
}