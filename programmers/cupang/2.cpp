#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int answer = 0;
int solution(int N, int M, int T, int K);
void dfs(int cnt, int N, int M, int T, int K);
int main(void)
{
    cout << solution(4, 7, 2, 4) << '\n';
    return 0;
}

int solution(int N, int M, int T, int K)
{
    dfs(0, N, M, T, K);
    return answer;
}

void dfs(int cnt, int N, int M, int T, int K)
{
    if (cnt == N)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += v[i];

        if (sum == M)
        {
            for (int i = 0; i <= N - T; i++)
            {
                int total = 0;
                for (int j = 0; j < T; j++)
                    total += v[i + j];

                if (total > K)
                    break;

                if (i == N - T)
                    answer++;
            }
        }
        return;
    }

    for (int i = 0; i <= K; i++)
    {
        if (v.size() < N)
        {
            v.push_back(i);
            dfs(cnt + 1, N, M, T, K);
            v.pop_back();
        }
    }
}