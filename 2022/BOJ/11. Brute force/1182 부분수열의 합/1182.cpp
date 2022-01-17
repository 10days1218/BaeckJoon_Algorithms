#include <iostream>
using namespace std;

int num[20] = {
    0,
};
bool check[20] = {
    false,
};
int N, S;
int answer;

void combination(int next, int depth, int end)
{
    if (depth == end)
    {
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            if (check[i])
                total += num[i];
        }

        if (total == S)
            answer += 1;

        return;
    }

    for (int i = next; i < N; i++)
    {
        if (check[i])
            continue;

        check[i] = true;
        combination(i, depth + 1, end);
        check[i] = false;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> num[i];

    for (int i = 1; i <= N; i++)
    {
        combination(0, 0, i);
    }

    cout << answer << "\n";

    return 0;
}