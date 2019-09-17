#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (i == 0 || j == 0)
                continue;

            if (board[i][j] == 1)
            {
                board[i][j] = min(min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    if (answer == 0)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                answer = max(answer, board[i][j]);
            }
        }
    }
    return answer * answer;
}

int main(void)
{
    vector<vector<int>> v = {{0, 0, 1, 1}, {1, 1, 1, 1}};
    // {{0, 1, 1, 1},
    //  {1, 1, 1, 1},
    //  {1, 1, 1, 1},
    //  {0, 0, 1, 0}};
    int ans = solution(v);
    cout << ans;
    return 0;
}