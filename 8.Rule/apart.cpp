//#2775
#include <iostream>
using namespace std;

int main(void)
{
    int num = 0;
    cin >> num;
    int *in1 = new int[num];
    int *in2 = new int[num];
    int maximum = 0;

    for (int i = 0; i < num; i++)
    {
        cin >> in1[i];
        cin >> in2[i];
    }

    int array[15][15] = {0};

    for (int i = 0; i < 15; i++)
    {
        array[0][i] = i + 1;
        array[i][0] = 1;
    }

    for (int i = 1; i < 15; i++)
    {
        for (int j = 1; j < 15; j++)
            array[i][j] = array[i - 1][j] + array[i][j - 1];
    }

    for (int i = 0; i < num; i++)
    {
        int index1 = in1[i];
        int index2 = in2[i];
        cout << array[index1][index2 - 1] << endl;
    }

    return 0;
}