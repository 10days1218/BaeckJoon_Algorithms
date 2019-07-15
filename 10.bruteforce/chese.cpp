//#1018
#include <bits/stdc++.h>
using namespace std;

int countPaint(char, int, int);
int main(void)
{
    int M, N = 0;
    cin >> N >> M;
    vector<vector<char>> v(M, vector<char>(N, 0));
    int count = 0;

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            v[i][j] = str.charAt(j);
        }
    }

    return 0;
}

int countPaint(char start, int M, int N)
{
    int answer = 0;
    return answer;
}