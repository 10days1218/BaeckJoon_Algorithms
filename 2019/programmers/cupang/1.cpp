#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int min_postion, int max_position, vector<int> positions);
int main(void)
{
    ;
    return 0;
}

vector<int> solution(int n, int min_postion, int max_position, vector<int> positions)
{
    int length = max_position - min_postion;
    int gap = length / (n - 1);
    vector<int> houses;
    vector<int> answer;
    vector<bool> check;
    for (int i = min_postion; i <= max_position; i += gap)
        houses.push_back(i);

    check.assign(n, false);

    for (int i = 0; i < positions.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            ;
        }
    }
}