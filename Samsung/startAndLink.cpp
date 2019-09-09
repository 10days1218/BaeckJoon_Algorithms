//$14889
#include <bits/stdc++.h>
using namespace std;

int arr[21][21] = {0};
bool check[21] = {false};
int answer = INT_MAX;
int n;
void makeTeam(int count, int position)
{
    if (count == n / 2)
    {
        int team1 = 0, team2 = 0;
        vector<int> v1, v2;
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
            {
                v1.push_back(i);
                if (v1.size() == n / 2)
                {
                    for (int j = 0; j < v1.size() - 1; j++)
                    {
                        for (int k = j + 1; k < v1.size(); k++)
                        {
                            int l, m;
                            l = v1[j], m = v1[k];
                            team1 += (arr[l][m] + arr[m][l]);
                        }
                    }
                }
            }
            else
            {
                v2.push_back(i);
                if (v2.size() == n / 2)
                {
                    for (int j = 0; j < v2.size() - 1; j++)
                    {
                        for (int k = j + 1; k < v2.size(); k++)
                        {
                            int l, m;
                            l = v2[j], m = v2[k];
                            team2 += (arr[l][m] + arr[m][l]);
                        }
                    }
                }
            }
        }
        answer = min(answer, abs(team1 - team2));
        cout << answer << '\n';
        return;
    }

    else
    {
        for (int i = position; i <= n; i++)
        {
            if (check[i] == false)
            {
                check[i] = true;
                makeTeam(count + 1, i + 1);
                check[i] = false;
            }
        }
    }
    cout << answer << '\n';
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            makeTeam(1, i);
            check[i] = false;
        }
    }

    cout << answer << '\n';
    return 0;
}