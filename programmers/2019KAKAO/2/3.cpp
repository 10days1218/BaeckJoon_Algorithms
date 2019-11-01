//https: //programmers.co.kr/learn/courses/30/lessons/60059
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> newKey)
{
    int len = newKey[0].size();
    vector<vector<int>> copy(len);

    for (int i = 0; i < len; i++)
    {
        copy[i].resize(len);
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            copy[j][len - i - 1] = newKey[i][j];
        }
    }
    return copy;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    int cnt = 0;
    lock.resize(lock.size() * 3);
    int newSize = lock[0].size() * 3;

    for (int i = 0; i < lock.size(); i++)
    {
        lock[i].resize(newSize);
    }

    //가운데로 옮기기
    int originalSize = lock[0].size() / 3;
    for (int i = 0; i < originalSize; i++)
    {
        for (int j = 0; j < originalSize; j++)
        {
            lock[originalSize + i][originalSize + j] = lock[i][j];
            if (lock[originalSize + i][originalSize + j] == 0)
                cnt++;
            lock[i][j] = -1;
        }
    }

    for (int i = 0; i < lock[0].size(); i++)
    {
        for (int j = 0; j < lock[0].size(); j++)
        {
            if (i >= originalSize && i < originalSize * 2 && j >= originalSize && j < originalSize * 2)
                continue;
            lock[i][j] = -1;
        }
    }

    vector<vector<int>> newKey = key;
    int len = newKey[0].size();
    int lockSize = lock[0].size();
    int correct = 0;
    int bump = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        newKey = rotate(newKey);
        for (int i = 0; i < lockSize - len; i++)
        {
            for (int j = 0; j < lockSize - len; j++)
            {
                for (int k = 0; k < len; k++)
                {
                    for (int l = 0; l < len; l++)
                    {
                        if (newKey[k][l] == 1 && lock[i + k][j + l] == 0)
                        {
                            correct++;
                        }

                        if (newKey[k][l] == 1 && lock[i + k][j + l] == 1)
                        {
                            bump++;
                        }
                    }
                }
                if (cnt == correct && !bump)
                {
                    answer = true;
                    return answer;
                }
                correct = 0, bump = 0;
            }
        }
    }
    return answer;
}

// int main(void)
// {
//     vector<vector<int>> k = {{0, 0, 0},
//                              {1, 0, 0},
//                              {0, 1, 1}};
//     vector<vector<int>> l = {{1, 1, 1},
//                              {1, 1, 0},
//                              {1, 0, 1}};

//     cout << solution(k, l) << '\n';
//     return 0;
// }