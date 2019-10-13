#define ABS(x) (x > 0 ? x : -(x))
#define INF 10000
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int S[17][17] = {
    0,
};
int visited[17] = {
    0,
};
int N, res;
//vector<int> A, B;

int calc_taste(vector<int> &v)
{
    int x = 0;
    for (int i = 0; i < (N / 2); i++)
    {
        for (int j = 0; j < (N / 2); j++)
        {
            if (i != j)
            {
                x += S[v[i]][v[j]];
            }
        }
    }
    return x;
}

int getResult()
{
    vector<int> a; // 선택된 팀
    vector<int> b; // 선택되지 않은 팀

    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            a.push_back(i);
        else
            b.push_back(i);
    }
    //시너지의 차 구하기
    return ABS(calc_taste(a) - calc_taste(b));
}

void dfs(int k, int cnt)
{
    visited[k] = true;

    if (cnt == N / 2)
    {
        res = min(res, getResult());
    }
    else
    {
        for (int i = k + 1; i <= N; i++)
        {
            dfs(i, cnt + 1);
        }
    }

    visited[k] = false;
}

int main()
{
    int T;

    freopen("input.txt", "r", stdin);

    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> N;
        res = INF;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin >> S[i][j];
        dfs(1, 1);
        cout << "#" << test_case << ' ' << res << '\n';
    }
    return 0; //정상종료
}