#include <iostream>
using namespace std;

int main(void)
{
    int num = 0;
    cin >> num;
    int *apart = new int[num * 2];
    int maximum = 0;

    for (int i = 0; i < num * 2; i++)
    {
        cin >> apart[i];
        if (i % 2 == 0)
        {
            maximum = max(maximum, apart[i]);
        }
    }

    int array[14][14] = {0};

    for (int i = 1; i <= 14; i++)
        array[0][i - 1] = i;

    for (int i = 1; i <= maximum; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            for (int k = 0; k <= j; k++)
                array[i][j] += array[i - 1][k];
        }
    }

    for (int i = 0; i < num * 2; i += 2)
    {
        int index1 = apart[i];
        int index2 = apart[i + 1];
        cout << array[index1][index2 - 1] << endl;
    }

    return 0;
}