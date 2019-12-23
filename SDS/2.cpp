#include <bits/stdc++.h>
using namespace std;

struct VALUE
{
    int y;
    int x;
    int value;
};
int maps[9][9];
vector<VALUE> wrong;
vector<VALUE> change;

void solve(int k);
void sudoku(int y, int x);
bool check(int y, int x, int v);
void printSudoku();

int main()
{
    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; test_case++)
    {
        int k;
        cin >> k;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> maps[i][j];
            }
        }
        solve(k);
    }
    return 0;
}

void solve(int k)
{
    map<int, vector<VALUE>> numbers;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            numbers[maps[i][j]].push_back({i, j, maps[i][j]});
        }

        for (int i = 1; i <= 9; i++)
        {
            if (numbers.find(i)->second.size() == 2)
            {
                wrong.push_back(numbers[i][0]);
                wrong.push_back(numbers[i][1]);
            }
        }
        numbers.clear();
    }

    for (int i = 0; i < wrong.size(); i++)
    {
        int y = wrong[i].y, x = wrong[i].x, value = wrong[i].value;
        if (!check(y, x, value))
        {
            // wrong.erase(wrong.begin() + i);
            maps[y][x] = 0;
        }
        else
        {
            change.push_back(wrong[i]);
        }
    }

    for (int i = 0; i < change.size(); i++)
    {
        int y = change[i].y, x = change[i].x, value = change[i].value;
        cout << y << " " << x << '\n';
        // sudoku(y, x);
    }
}

bool check(int y, int x, int v)
{
    int numberY[9] = {0};
    int numberX[9] = {0};
    int numberSquare[9] = {0};
    bool check = true;
    // vector<int> v;

    for (int i = 0; i < 9; i++)
    {
        if (maps[y][i])
            numberX[maps[y][i] - 1]++;

        if (maps[i][x])
            numberY[maps[i][x] - 1]++;
    }

    int startY = y / 3, startX = x / 3;
    startY *= 3, startX *= 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (maps[startY][startX + j])
                numberSquare[maps[startY][startX + j] - 1]++;
        }
        startY++;
    }

    if (numberY[v] == 2 && numberY[v] == 2 && numberSquare[v] == 2)
    {
        check = false;
    }

    return check;
}

void sudoku(int y, int x)
{
    int number[9] = {0};
    vector<int> v;

    for (int i = 0; i < 9; i++)
    {
        if (maps[y][i])
            number[maps[y][i] - 1] = 1;

        if (maps[i][x])
            number[maps[i][x] - 1] = 1;
    }

    int startY = y / 3, startX = x / 3;
    startY *= 3, startX *= 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (maps[startY][startX + j])
                number[maps[startY][startX + j] - 1] = 1;
        }
        startY++;
    }

    for (int i = 0; i < 9; i++)
        if (!number[i])
            v.push_back(i + 1);

    if ((int)v.size() == 0)
        return;

    int nY = y, nX = x;

    while (1)
    {
        if ((++nX) == 9)
        {
            nY++, nX = 0;
            if (nY == 9)
            {
                maps[y][x] = v[0];
                // printSudoku();
                for (int i = 0; i < wrong.size(); i++)
                {
                    int ansY = wrong[i].y, ansX = wrong[i].x;
                    cout << ansY + 1 << " " << ansX + 1 << " " << maps[ansY][ansX] << '\n';
                }
                exit(0);
            }
        }
        if (nY == 9)
            break;
        if (maps[nY][nX] == 0)
            break;
    }

    for (int i = 0; i < v.size(); i++)
    {
        maps[y][x] = v[i];
        sudoku(nY, nX);
        maps[y][x] = 0;
    }
}

void printSudoku()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << maps[i][j] << " ";
        }
        cout << '\n';
    }
}