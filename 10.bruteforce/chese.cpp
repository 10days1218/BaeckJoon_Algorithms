//#1018
#include <bits/stdc++.h>
using namespace std;

int countPaint(char, int, int, vector<vector<char>> &v);
int main(void)
{
    int M, N = 0;
    cin >> N >> M;
    vector<vector<char>> v(N, vector<char>(M, 0));
    int count = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
            v[i][j] = str.at(j);
    }

    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
            count = min(count, countPaint(v[i][j], i, j, v));
    }

    cout << count << '\n';

    return 0;
}

int countPaint(char start, int x, int y, vector<vector<char>> &v)
{
    int answer = 0;
    int index = 0;

    if (start == 'W')
    {
        string check1 = "WBWBWBWB";
        string check2 = "BWBWBWBW";
        for (int i = x; i < x + 8; i++)
        {
            for (int j = y; j < y + 8; j++)
            {
                if (i % 2 == 0)
                    if (check1.at(index) != v[i][j])
                        answer++;
                if (i % 2 == 1)
                    if (check2.at(index) != v[i][j])
                        answer++;

                index++;
            }
            index = 0;
        }
    }

    if (start == 'B')
    {
        string check1 = "BWBWBWBW";
        string check2 = "WBWBWBWB";
        for (int i = x; i < x + 8; i++)
        {
            for (int j = y; j < y + 8; j++)
            {
                if (i % 2 == 0)
                    if (check1.at(index) != v[i][j])
                        answer++;
                if (i % 2 == 1)
                    if (check2.at(index) != v[i][j])
                        answer++;

                index++;
            }
            index = 0;
        }
    }
    return answer;
}