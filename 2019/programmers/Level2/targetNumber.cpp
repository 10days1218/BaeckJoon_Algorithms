#include <bits/stdc++.h>
using namespace std;
bool check[21] = {false};
int answer = 0;

void dfs(vector<int> numbers, int target, int idx, int count)
{
    if (idx == numbers.size())
    {
        if (count == target)
            answer++;
        return;
    }
    dfs(numbers, target, idx + 1, count + numbers[idx]);
    dfs(numbers, target, idx + 1, count - numbers[idx]);
}

int solution(vector<int> numbers, int target)
{
    dfs(numbers, target, 0, 0);
    cout << answer;
    return answer;
}

int main(void)
{
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    solution(numbers, target);
    return 0;
}