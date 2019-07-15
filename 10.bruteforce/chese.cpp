//#1018
#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string white[8] = {
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"}

};

string black[8] = {
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"}

};

int whiteFirst(int y, int x)
{
    int answer = 0;
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if (v[i][j] != white[i - y][j - x])
                answer++;
        }
    }

    return answer;
}

int BlackFirst(int y, int x)
{
    int answer = 0;
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if (v[i][j] != black[i - y][j - x])
                answer++;
        }
    }
    return answer;
}
int main(void)
{
    int M, N = 0;
    cin >> N >> M;
    v.resize(N);
    int count = INT_MAX;

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i + 7 < N; i++)
        for (int j = 0; j + 7 < M; j++)
            count = min(count, min(whiteFirst(i, j), BlackFirst(i, j)));

    cout << count << '\n';

    return 0;
}