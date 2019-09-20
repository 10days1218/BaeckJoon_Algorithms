#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int count[3] = {0};
    int player[3] = {1, 2, 3};
    int arr[5] = {3, 1, 2, 4, 5};
    int index2 = 0;
    int index3 = 0;
    int count3 = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        // cout << player[0] << player[1] << player[2] << '\n';
        for (int j = 0; j < 3; j++)
        {
            if (answers[i] == player[j])
            {
                count[j]++;
            }
        }
        player[0] = player[0] % 5 + 1;
        count3++;
        if (player[1] == 2)
        {
            index2++;
            player[1] = index2 % 5 != 0 ? index2 % 5 : 5;
            if (player[1] == 2)
            {
                player[1]++;
                index2++;
                continue;
            }
        }

        else
        {
            player[1] = 2;
        }

        if (count3 == 2)
        {
            count3 = 0;
            player[2] = arr[(++index3) % 5];
        }
    }

    int m = max(max(count[0], count[1]), count[2]);
    for (int i = 0; i < 3; i++)
        if (m == count[i])
            answer.push_back(i + 1);

    return answer;
}

int main(void)
{
    vector<int> tmp = solution({1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5});
    for (int i = 0; i < tmp.size(); i++)
        cout << tmp[i] << " ";
    return 0;
}