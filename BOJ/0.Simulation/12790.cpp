//https://www.acmicpc.net/problem/12790
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int hp, mp, power, shield, hp1, mp2, power2, shield2;
        cin >> hp >> mp >> power >> shield >> hp1 >> mp2 >> power2 >> shield2;

        hp += hp1, mp += mp2, power += power2, shield += shield2;
        hp = hp < 1 ? 1 : hp;
        mp = mp < 1 ? 1 : mp;
        power = power < 0 ? 0 : power;
        int ret = hp * 1 + mp * 5 + 2 * power + 2 * shield;
        cout << ret << '\n';
    }
    return 0;
}