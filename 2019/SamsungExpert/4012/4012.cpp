#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int foods[17][17];
int N;
bool selected[17];
int answer = INT_MAX;

void dfs(int cnt, int idx)
{
    if (cnt == N / 2)
    {
        int a = 0, b = 0;
        //int index_a = 0, index_b = 0;
        vector<int> v_a, v_b;
        //v_a.resize(N / 2);
        //v_b.resize(N / 2);
        for (int i = 0; i < N; i++)
        {
            if (selected[i])
            {
                v_a.push_back(i);
                if (v_a.size() == N / 2)
                {
                    for (int j = 0; j < v_a.size() - 1; j++)
                    {
                        for (int k = j + 1; k < v_a.size(); k++)
                        {
                            int l, m;
                            l = v_a[j], m = v_a[k];
                            a += (foods[l][m] + foods[m][l]);
                        }
                    }
                }
            }
            else
            {
                v_b.push_back(i);
                if (v_b.size() == N / 2)
                {
                    for (int j = 0; j < v_b.size() - 1; j++)
                    {
                        for (int k = j + 1; k < v_b.size(); k++)
                        {
                            int l, m;
                            l = v_b[j], m = v_b[k];
                            b += (foods[l][m] + foods[m][l]);
                        }
                    }
                }
            }
        }
        answer = min(answer, abs(a - b));
        return;
    }

    for (int i = idx; i < N; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;
            dfs(cnt + 1, idx + 1);
            selected[i] = false;
        }
    }
}
int main(int argc, char **argv)
{
    int test_case;
    int T;

    freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> foods[i][j];
            }
        }
        dfs(0, 0);
        cout << "#" << test_case << " " << answer << '\n';
        cout << '\n';
        fill_n(&foods[0][0], N * N, 0);
        answer = INT_MAX;
    }
    return 0;
}