// #include <string>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> answer = {-1};
int max_diff = -1;

void dfs(vector<int> lion, vector<int> info, int cnt, int m, int n)
{

    if (cnt == 0)
    {

        int lion_score = 0;
        int apeach_score = 0;
        // 라이언 어피치 점수 계산
        for (int i = 0; i < 11; i++)
        {
            if (lion[i] > info[i])
                lion_score += 10 - i;

            else if (info[i] > 0 && info[i] >= lion[i])
                apeach_score += 10 - i;
        }

        // 라이언이 점수가 더 크다면
        if (lion_score > apeach_score)
        {
            // 점수 차이 계산
            if (max_diff <= lion_score - apeach_score)
            {
                if (max_diff == lion_score - apeach_score)
                {
                    reverse(answer.begin(), answer.end());
                    reverse(lion.begin(), lion.end());
                    if (answer < lion)
                    {
                        for (int i = 0; i <= 10; i++)
                        {
                            answer[i] = lion[i];
                        }
                    }
                    reverse(answer.begin(), answer.end());
                    reverse(lion.begin(), lion.end());
                    return;
                }
                max_diff = lion_score - apeach_score;
                answer = lion;
            }
        }

        return;
    }

    for (int j = m; j < 11; j++)
    {
        for (int i = cnt; i > 0; i--)
        {
            lion[j] = i;
            dfs(lion, info, cnt - i, j + 1, n);
        }
        lion[j] = 0;
    }
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> lion(11, 0);

    dfs(lion, info, n, 0, n);

    return answer;
}

int main(void)
{
    vector<int> pro;
    vector<int> ans;
    int n;

    pro = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    n = 5;

    ans = solution(n, pro);

    for (int i = 0; i < 11; i++)
        cout << answer[i] << " ";
    cout << "\n";

    return 0;
}