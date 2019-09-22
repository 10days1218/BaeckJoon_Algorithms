#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
bool visit[201] = {false};
void dfs(int n, vector<vector<int>> computers, int v)
{
    visit[v] = true;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == false && computers[v][i] == 1)
        {
            dfs(n, computers, i);
        }
    }
}
int solution(int n, vector<vector<int>> computers)
{
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            answer++;
            dfs(n, computers, 0);
        }
    }
    //cout << answer;
    return answer;
}

int main(void)
{
    vector<vector<int>> com = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int n = 3;
    solution(n, com);
}