#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int w_board[8][8] = {
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1}};

int b_board[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}};

int input_board[50][50] = {
    0,
};

int N, M;

int main(void)
{
    int answer = INT_MAX;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == 'W')
                input_board[i][j] = 1;

            else
                input_board[i][j] = 0;
        }
    }

    int moving_row = N - 8;
    int moving_col = M - 8;

    for (int r = 0; r <= moving_row; r++)
    {
        for (int c = 0; c <= moving_col; c++)
        {
            int tmp_w = 0;
            int tmp_b = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (input_board[i + r][j + c] != b_board[i][j])
                    {
                        tmp_b += 1;
                    }

                    else if (input_board[i + r][j + c] != w_board[i][j])
                    {
                        tmp_w += 1;
                    }
                }
            }
            answer = min(answer, min(tmp_w, tmp_b));
        }
    }

    cout << answer << "\n";

    return 0;
}