#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 300000
int card[MAX];
bool check[MAX] = {
    false,
};
int N, M, answer;

void combination(int depth, int next)
{
    if (depth == 3)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (check[i])
                sum += card[i];
        }

        if (sum < M)
            answer = max(answer, sum);

        if (sum == M)
        {
            answer = sum;
            return;
        }
        return;
    }

    for (int i = next; i < N; i++)
    {
        if (check[i])
            continue;
        check[i] = true;

        combination(depth + 1, i);
        check[i] = false;
    }
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> card[i];

    combination(0, 0);
    cout << answer << endl;

    return 0;
}