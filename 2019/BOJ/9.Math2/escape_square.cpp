//#1085
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int x, y, w, h = 0;
    int gap_x, gap_y, ans = 0;
    cin >> x >> y >> w >> h;

    ans = min(x, w - x);
    ans = min(ans, min(y, h - y));

    cout << ans << '\n';
    return 0;
}