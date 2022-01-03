//#10250
#include <iostream>
using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    int *H = new int[n];
    int *W = new int[n];
    int *N = new int[n];
    int count = 0;
    int room = 1;
    int i = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> H[i] >> W[i] >> N[i];
    }

    while (1)
    {
        count++;
        room += 100;
        if (count == N[i])
        {
            cout << room << endl;
            i++;
            room = 1;
            count = 0;
        }

        if (room / 100 == H[i])
        {
            room = room % 100;
            room++;
        }

        if (i == n)
            break;
    }
    return 0;
}