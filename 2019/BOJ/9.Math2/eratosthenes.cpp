//https://www.acmicpc.net/problem/1929
#include <bits/stdc++.h>
using namespace std;

unsigned char sieve[(1000000 + 7) / 8 + 1];

inline bool isPrime(int k);
inline void setComposite(int k);
// void eratosthenes();

int main(void)
{
    int m, n;
    cin >> m >> n;

    fill(sieve, sieve + sizeof(sieve) / sizeof(char), 255);
    setComposite(0);
    setComposite(1);
    int sqrtn = int(sqrt(n));

    for (int i = 2; i <= sqrtn; i++)
    {
        if (isPrime(i))
            for (int j = i * 2; j <= n; j += i)
                setComposite(j);
    }

    for (int i = m; i <= n; i++)
    {
        if (sieve[i >> 3] & (1 << (i & 7)))
            cout << i << '\n';
    }
    return 0;
}

inline bool isPrime(int k)
{
    return sieve[k >> 3] & (1 << (k & 7));
}

inline void setComposite(int k)
{
    sieve[k >> 3] &= ~(1 << (k & 7));
}