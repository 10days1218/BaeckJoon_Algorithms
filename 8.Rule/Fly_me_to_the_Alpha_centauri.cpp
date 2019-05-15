//#1011
#include <iostream>
using namespace std;

int main(void)
{
    int num = 0;
    cin >> num;

    int *x = new int[num];
    int *y = new int[num];

    for (int i = 0; i < num; i++)
        cin >> x[i] >> y[i];

    return 0;
}