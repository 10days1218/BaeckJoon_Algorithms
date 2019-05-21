//#1475
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int roomNumber = 0;
    cin >> roomNumber;

    string str = to_string(roomNumber);
    int len = str.length();
    int number[9] = {0};

    for (int i = 0; i < len; i++)
    {
        switch (str[i])
        {
        case '0':
            number[0] += 1;
            break;
        case '1':
            number[1] += 1;
            break;
        case '2':
            number[2] += 1;
            break;
        case '3':
            number[3] += 1;
            break;
        case '4':
            number[4] += 1;
            break;
        case '5':
            number[5] += 1;
            break;
        case '6':
            number[6] += 1;
            break;
        case '7':
            number[7] += 1;
            break;
        case '8':
            number[8] += 1;
            break;
        case '9':
            number[6] += 1;
            break;
        }
    }

    int max_n = 0;
    int index = 0;

    for (int i = 0; i < 9; i++)
    {
        if (i == 6)
        {
            if (number[i] % 2 == 1)
                number[i] = number[i] / 2 + 1;
            else
                number[i] = number[i] / 2;
        }

        max_n = max(max_n, number[i]);
    }

    cout << max_n << endl;
    return 0;
}