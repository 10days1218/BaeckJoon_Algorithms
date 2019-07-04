//#1193
#include <iostream>
using namespace std;
int main(void)
{
    int num = 0;
    int n1, n2 = 0;
    int count = 1;
    int total = 0;
    bool check = true;
    cin >> num;

    while (1)
    {
        total += count;
        if (total >= num)
        {
            break;
        }
        count++;
    }

    int index = num - (total - count) - 1;
''
    if (count % 2 == 0)
    {
        n1 = 1;
        n2 = count;
        check = true;
    }
    else
    {
        n1 = count;
        n2 = 1;
        check = false;
    }

    for (int i = 0; i < index; i++)
    {
        if (check)
        {
            n1++;
            n2--;
        }
        else
        {
            n1--;
            n2++;
        }
    }

    cout << n1 << '/' << n2;
    return 0;
}