#include <iostream>
using namespace std;

#define MAX 15

int board[MAX];
int answer;
int n;

bool is_pormising(int x)
{
    for (int i = 0; i < x; i++)
        if (board[i] == board[x] || abs(x - i) == abs(board[x] - board[i]))
            return false;

    return true;
}

void n_queen(int x)
{
    if (x == n)
    {
        answer += 1;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        board[x] = i;
        if (is_pormising(x))
            n_queen(x + 1);
    }
}

int main(void)
{
    cin >> n;

    n_queen(0);
    cout << answer << "\n";

    return 0;
}