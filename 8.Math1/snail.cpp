//#2869
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A, B, V, N = 0;
    cin >> A >> B >> V;

    cout << (V - B - 1) / (A - B) + 1 << endl;
    return 0;
}