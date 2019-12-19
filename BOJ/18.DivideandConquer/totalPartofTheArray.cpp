//#https://www.acmicpc.net/problem/2104
#include <bits/stdc++.h>
using namespace std;

long long v[100000];
long long solve(int left, int right);

int main(void)
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << solve(0, n - 1) << '\n';
    return 0;
}

long long solve(int left, int right)
{
    //기저 사례
    if (left == right)
        return v[left] * v[left];

    int mid = (left + right) / 2;
    //주어진 배열의 최대값
    long long ret = max(solve(left, mid), solve(mid + 1, right));

    //더 작은 값 찾기
    int low = mid, high = mid + 1;
    long long pivot = min(v[low], v[high]), sum = v[low] + v[high];
    ret = max(ret, sum * pivot);

    while (left < low || high < right)
    {
        if (high < right && (low == left || v[low - 1] < v[high + 1]))
        {
            high++;
            sum += v[high];
            pivot = min(pivot, v[high]);
        }
        else
        {
            low--;
            sum += v[low];
            pivot = min(pivot, v[low]);
        }
        ret = max(ret, sum * pivot);
    }

    return ret;
}