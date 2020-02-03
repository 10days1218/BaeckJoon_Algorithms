//https://www.acmicpc.net/problem/17825
#include <bits/stdc++.h>
using namespace std;

int maps[33][6] = {
    {0, 1, 2, 3, 4, 5},       //0
    {2, 2, 3, 4, 5, 9},       //1
    {4, 3, 4, 5, 9, 10},      //2
    {6, 4, 5, 9, 10, 11},     //3
    {8, 5, 9, 10, 11, 12},    //4
    {10, 6, 7, 8, 16, 29},    //5
    {13, 7, 8, 16, 29, 30},   //6
    {16, 8, 16, 29, 30, 31},  //7
    {19, 16, 29, 30, 31, 32}, //8
    {12, 10, 11, 12, 13, 17}, //9
    {14, 11, 12, 13, 17, 18}, //10
    {16, 12, 13, 17, 18, 19}, //11
    {18, 13, 17, 18, 19, 20}, //12
    {20, 14, 15, 16, 29, 30}, //13
    {22, 15, 16, 29, 30, 31}, //14
    {24, 16, 29, 30, 31, 32}, //15
    {25, 29, 30, 31, 32, 32}, //16
    {22, 18, 19, 20, 21, 25}, //17
    {24, 19, 20, 21, 25, 26}, //18
    {26, 20, 21, 25, 26, 27}, //19
    {28, 31, 25, 26, 27, 28}, //20
    {30, 22, 23, 24, 16, 29}, //21
    {28, 23, 24, 16, 29, 30}, //22
    {27, 24, 16, 29, 30, 31}, //23
    {26, 16, 29, 30, 31, 32}, //24
    {32, 26, 27, 28, 31, 32}, //25
    {34, 27, 28, 31, 32, 32}, //26
    {36, 28, 31, 32, 32, 32}, //27
    {38, 31, 32, 32, 32, 32}, //28
    {30, 30, 31, 32, 32, 32}, //29
    {35, 31, 32, 32, 32, 32}, //30
    {40, 32, 32, 32, 32, 32}, //31
    {0, 32, 32, 32, 32, 32}   //32

};

int dice[10];
int select[10];
int answer;

void solve(int n);
int main(void)
{
    for (int i = 0; i < 10; i++)
        cin >> dice[i];

    solve(0);

    cout << answer << '\n';
    return 0;
}

void solve(int n)
{
    if (n == 10)
    {
        int sum = 0;
        int pose[4];
        int occupation[33];
        fill(pose, pose + 4, 0);
        fill(occupation, occupation + 33, 0);
        occupation[0] = 4;

        for (int turn = 0; turn < 10; turn++)
        {
            int horse = select[turn];
            int current = pose[horse];
            int move = dice[turn];
            int next = maps[current][move];
            int score = maps[next][0];

            if (occupation[next] > 0 && next != 32)
                return;

            sum += score;
            pose[horse] = next;
            occupation[current]--;
            occupation[next]++;
        }

        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        select[n] = i;
        solve(n + 1);
    }
}