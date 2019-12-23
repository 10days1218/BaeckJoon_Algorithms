#include <bits/stdc++.h>
using namespace std;

void rotate(int dir);
void printCube(int p);
int cube[6][3][3] =
    {
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}},
        {{10, 11, 12},
         {13, 14, 15},
         {16, 17, 18}},
        {{19, 20, 21},
         {22, 23, 24},
         {25, 26, 27}},
        {{28, 29, 30},
         {31, 32, 33},
         {34, 35, 36}},
        {{37, 38, 39},
         {40, 41, 42},
         {43, 44, 45}},
        {{46, 47, 48},
         {49, 50, 51},
         {52, 53, 54}}};

int main(void)
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int cmd;
            cin >> cmd;
            rotate(cmd);
        }
        int p;
        cin >> p;
        cout << '#' << i + 1 << " ";
        printCube(p);
        // cout << '\n';
        // for (int i = 1; i <= 6; i++)
        //     printCube(i);
    }
    return 0;
}

void rotate(int dir)
{
    if (dir == 1)
    {
        int tmp[3];
        // B 배열 저장
        tmp[0] = cube[1][0][0], tmp[1] = cube[1][1][0], tmp[2] = cube[1][2][0];
        // C -> B
        cube[1][0][0] = cube[2][0][0], cube[1][1][0] = cube[2][1][0], cube[1][2][0] = cube[2][2][0];
        // D -> C
        cube[2][0][0]

    }

    else if (dir == 2)
    {
        int tmp[3];
        // B 배열 저장
        tmp[0] = cube[1][0][1], tmp[1] = cube[1][1][1], tmp[2] = cube[1][2][1];
        // C -> B 배열 반전
        cube[1][0][1] = cube[2][2][1], cube[1][1][1] = cube[2][1][1], cube[1][2][1] = cube[2][0][1];
        // D -> C 배열 반전 x
        cube[2][0][1] = cube[3][0][1], cube[2][1][1] = cube[3][1][1], cube[2][2][1] = cube[3][2][1];
        // A -> D 배열 반전
        cube[3][0][1] = cube[0][2][1], cube[0][1][1] = cube[0][1][1], cube[3][2][1] = cube[0][0][1];
        // B -> A 배열 반전 x
        cube[0][0][1] = tmp[0], cube[0][1][1] = tmp[1], cube[0][2][1] = tmp[2];
    }

    else if (dir == 3)
    {
        int tmp[3];
        tmp[0] = cube[1][0][2], tmp[1] = cube[1][1][2], tmp[2] = cube[1][2][2];
        // C -> B 배열 반전
        cube[1][0][2] = cube[2][2][2], cube[1][1][2] = cube[2][1][2], cube[1][2][2] = cube[2][0][2];
        // D -> C 배열 반전 x
        cube[2][0][2] = cube[3][0][2], cube[2][1][2] = cube[3][1][2], cube[2][2][2] = cube[3][2][2];
        // A -> D 배열 반전
        cube[3][0][2] = cube[0][2][2], cube[0][1][2] = cube[0][1][2], cube[3][2][2] = cube[0][0][2];
        // B -> A 배열 반전 x
        cube[0][0][2] = tmp[0], cube[0][1][2] = tmp[1], cube[0][2][2] = tmp[2];
    }

    else if (dir == 4)
    {
        int tmp[3];
        // B 저장
        tmp[0] = cube[1][0][0], tmp[1] = cube[1][1][0], tmp[2] = cube[1][2][0];
        // A -> B 배열 반전x
        cube[1][0][0] = cube[0][0][0], cube[1][1][0] = cube[0][1][0], cube[1][2][0] = cube[0][2][0];
        // D -> A 배열 반전
        cube[0][0][0] = cube[3][2][0], cube[0][1][0] = cube[3][1][0], cube[0][2][0] = cube[3][0][0];
        // C -> D 배열 반전x
        cube[3][0][0] = cube[2][0][0], cube[3][1][0] = cube[2][1][0], cube[3][2][0] = cube[2][2][0];
        // B -> C 배열 반전
        cube[2][0][0] = tmp[2], cube[2][1][0] = tmp[1], cube[2][2][0] = tmp[0];
    }

    else if (dir == 5)
    {
        int tmp[3];
        // B 저장
        tmp[0] = cube[1][0][1], tmp[1] = cube[1][1][1], tmp[2] = cube[1][2][1];
        // A -> B 배열 반전x
        cube[1][0][1] = cube[0][0][1], cube[1][1][1] = cube[0][1][1], cube[1][2][1] = cube[0][2][1];
        // D -> A 배열 반전
        cube[0][0][1] = cube[3][2][1], cube[0][1][1] = cube[3][1][1], cube[0][2][1] = cube[3][0][1];
        // C -> D 배열 반전x
        cube[3][0][1] = cube[2][0][1], cube[3][1][1] = cube[2][1][1], cube[3][2][0] = cube[2][2][1];
        // B -> C 배열 반전
        cube[2][0][1] = tmp[2], cube[2][1][1] = tmp[1], cube[2][2][1] = tmp[0];
    }

    else if (dir == 6)
    {
        int tmp[3];
        // B 저장
        tmp[0] = cube[1][0][2], tmp[1] = cube[1][1][2], tmp[2] = cube[1][2][2];
        // A -> B 배열 반전x
        cube[1][0][2] = cube[0][0][2], cube[1][1][2] = cube[0][1][2], cube[1][2][2] = cube[0][2][2];
        // D -> A 배열 반전
        cube[0][0][2] = cube[3][2][2], cube[0][1][2] = cube[3][1][2], cube[0][2][2] = cube[3][0][2];
        // C -> D 배열 반전x
        cube[3][0][2] = cube[2][0][2], cube[3][1][2] = cube[2][1][2], cube[3][2][2] = cube[2][2][2];
        // B -> C 배열 반전
        cube[2][0][2] = tmp[2], cube[2][1][2] = tmp[1], cube[2][2][2] = tmp[0];
    }

    else if (dir == 7)
    {
        int tmp[3];
        //B 배열 저장
        tmp[0] = cube[1][0][0], tmp[1] = cube[1][0][1], tmp[2] = cube[1][0][2];
        //F -> B 배열 반전x
        cube[1][0][0] = cube[5][0][0], cube[1][0][1] = cube[5][0][1], cube[1][0][2] = cube[5][0][2];
        //D -> F 베열 반전
        cube[5][0][0] = cube[3][0][2], cube[5][0][1] = cube[3][0][1], cube[5][0][2] = cube[3][0][0];
        // E -> D 배열 반전 x
        cube[3][0][0] = cube[4][0][0], cube[3][0][1] = cube[4][0][1], cube[3][0][2] = cube[4][0][2];
        // B -> E 배열 만전
        cube[4][0][0] = tmp[2], cube[4][0][1] = tmp[1], cube[4][0][2] = tmp[0];
    }

    else if (dir == 8)
    {
        int tmp[3];
        //B 배열 저장
        tmp[0] = cube[1][1][0], tmp[1] = cube[1][1][1], tmp[2] = cube[1][1][2];
        //F -> B 배열 반전x
        cube[1][1][0] = cube[5][1][0], cube[1][1][1] = cube[5][1][1], cube[1][1][2] = cube[5][1][2];
        //D -> F 베열 반전
        cube[5][1][0] = cube[3][1][2], cube[5][1][1] = cube[3][1][1], cube[5][1][2] = cube[3][1][0];
        // E -> D 배열 반전 x
        cube[3][1][0] = cube[4][1][0], cube[3][1][1] = cube[4][1][1], cube[3][1][2] = cube[4][1][2];
        // B -> E 배열 만전
        cube[4][1][0] = tmp[2], cube[4][1][1] = tmp[1], cube[4][1][2] = tmp[0];
    }

    else if (dir == 9)
    {
        int tmp[3];
        //B 배열 저장
        tmp[0] = cube[1][2][0], tmp[1] = cube[1][2][1], tmp[2] = cube[1][2][2];
        //F -> B 배열 반전x
        cube[1][2][0] = cube[5][2][0], cube[1][2][1] = cube[5][2][1], cube[1][2][2] = cube[5][2][2];
        //D -> F 베열 반전
        cube[5][2][0] = cube[3][2][2], cube[5][2][1] = cube[3][2][1], cube[5][2][2] = cube[3][2][0];
        // E -> D 배열 반전 x
        cube[3][2][0] = cube[4][2][0], cube[3][2][1] = cube[4][2][1], cube[3][2][2] = cube[4][2][2];
        // B -> E 배열 만전
        cube[4][2][0] = tmp[2], cube[4][2][1] = tmp[1], cube[4][2][2] = tmp[0];
    }

    else if (dir == 10)
    {
        int tmp[3];
        //B 배열 저장
        tmp[0] = cube[1][0][0], tmp[1] = cube[1][0][1], tmp[2] = cube[1][0][2];
        // E -> B 배열 반전 x
        cube[1][0][0] = cube[4][0][0], cube[1][0][1] = cube[4][0][1], cube[1][0][2] = cube[4][0][2];
        // D -> E 배열 반전
        cube[4][0][0] = cube[3][0][2], cube[4][0][1] = cube[3][0][1], cube[4][0][2] = cube[3][0][0];
        // F -> D 배열 반전
        cube[3][0][0] = cube[5][0][2], cube[3][0][1] = cube[5][0][1], cube[3][0][2] = cube[5][0][0];
        // B -> F 배열 반전 x
        cube[5][0][0] = tmp[0], cube[5][0][1] = tmp[1], cube[5][0][2] = tmp[2];
    }

    else if (dir == 11)
    {
        int tmp[3];
        //B 배열 저장
        tmp[0] = cube[1][1][0], tmp[1] = cube[1][1][1], tmp[2] = cube[1][1][2];
        // E -> B 배열 반전 x
        cube[1][1][0] = cube[4][1][0], cube[1][1][1] = cube[4][1][1], cube[1][1][2] = cube[4][0][2];
        // D -> E 배열 반전
        cube[4][1][0] = cube[3][1][2], cube[4][1][1] = cube[3][1][1], cube[4][1][2] = cube[3][1][0];
        // F -> D 배열 반전
        cube[3][1][0] = cube[5][1][2], cube[3][1][1] = cube[5][1][1], cube[3][1][2] = cube[5][1][0];
        // B -> F 배열 반전 x
        cube[5][1][0] = tmp[0], cube[5][1][1] = tmp[1], cube[5][1][2] = tmp[2];
    }

    else if (dir == 12)
    {
        int tmp[3];
        //B 배열 저장
        tmp[0] = cube[1][2][0], tmp[1] = cube[1][2][1], tmp[2] = cube[1][2][2];
        // E -> B 배열 반전 x
        cube[1][2][0] = cube[4][2][0], cube[1][2][1] = cube[4][2][1], cube[1][2][2] = cube[4][2][2];
        // D -> E 배열 반전
        cube[4][2][0] = cube[3][2][2], cube[4][2][1] = cube[3][2][1], cube[4][2][2] = cube[3][2][0];
        // F -> D 배열 반전
        cube[3][2][0] = cube[5][2][2], cube[3][2][1] = cube[5][2][1], cube[3][2][2] = cube[5][2][0];
        // B -> F 배열 반전 x
        cube[5][2][0] = tmp[0], cube[5][2][1] = tmp[1], cube[5][2][2] = tmp[2];
    }
}

void printCube(int p)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << cube[p - 1][i][j] << " ";
        }
    }
    cout << '\n';
}