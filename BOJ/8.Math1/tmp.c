#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int arr[1000];
    arr[1] = 1;
    arr[2] = 2;

    int k, i;
    int loc = 3;
    int loop = 2;
    int val = 3;
    for (i = 0; i < 4; i++)
    {
        for (k = 0; k < loop; k++)
        {
            arr[loc++] = val;
        }
        val++;
        for (k = 0; k < loop; k++)
        {
            arr[loc++] = val;
        }
        val++;
        loop++;
    }
    printf("result : %d\n", arr[y - x]);
    return 0;
}