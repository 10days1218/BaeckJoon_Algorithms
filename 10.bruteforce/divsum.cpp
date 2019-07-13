//#2231
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int num;
    int answer = 0;
    cin >> num;

    for (int i = 1; i < num; i++)
    {
        answer += i;
        int tmp = i;
        while (tmp != 0)
        {
            answer += tmp % 10;
            tmp /= 10;
        }

        if (answer == num)
        {
            answer = i;
            break;
        }

        answer = 0;
    }

    cout << answer << '\n';
    return 0;
}