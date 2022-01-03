//https://www.acmicpc.net/problem/1725
#include <bits/stdc++.h>
using namespace std;

vector<int> h;
int solve(int left, int right);
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    h.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    cout << solve(0, n - 1) << '\n';

    return 0;
}

int solve(int left, int right)
{
    if (left == right)
        return h[left];

    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid + 1, right));

    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);
    ret = max(ret, height * 2);

    while (left < lo || hi < right)
    {
        if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
        {
            hi++;
            height = min(height, h[hi]);
        }
        else
        {
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}