//https://www.acmicpc.net/problem/5063
#include <bits/stdc++.h>
using namespace std;

struct AD
{
    int noAd;
    int YesAd;
    int ad;
};

vector<AD> v;
int main(void)
{
    int n;
    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].noAd >> v[i].YesAd >> v[i].ad;

    for (int i = 0; i < n; i++)
    {
        if (v[i].noAd < v[i].YesAd - v[i].ad)
        {
            cout << "advertise\n";
        }

        else if (v[i].noAd == v[i].YesAd - v[i].ad)
        {
            cout << "does not matter\n";
        }

        else if (v[i].noAd > v[i].YesAd - v[i].ad)
        {
            cout << "do not advertise\n";
        }
    }
    return 0;
}