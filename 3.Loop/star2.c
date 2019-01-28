#include <stdio.h>
int main(void)
{
    int a, b;
    int i, j, k = 0;
    scanf("%d", &a);

    b = a;

    for (i = 0; i < b; i++)
    {
        for (k = a - 1; k > 0; k--)
        {
            printf(" ");
        }

        for (j = 0; j <= i; j++)
        {
            printf("*");
        }
        a--;
        printf("\n");
    }

    return 0;
}