//#4948
#include <bits/stdc++.h>
using namespace std;

int prime_number(int n);

int main(void)
{
    vector<int> v;
    vector<bool> p(246913, true);
    int n = 0;
    int count = 0;
    p[0] = p[1] = false;

    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        v.push_back(n);
    }

    for (int i = 2; i < sqrt(246912); i++)
    {
        if (p[i])
        {
            for (int j = i * 2; j <= 246912; j += i)
                p[j] = false;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v[i] + 1; j <= 2 * v[i]; j++)
            if (p[j] == true)
                count++;
        cout << count << '\n';
        count = 0;
    }

    return 0;
}