#include <stdio.h>

int main(void)
{

    int a;
    int count = 0;

    scanf("%d", &a);

    if (a % 5 == 0)
    {
        printf("%d\n", a / 5);
        return 0;
    }

    while (a >= 3)
    {
        a -= 3;
        count++;
        if (a % 5 == 0)
        {
            printf("%d\n", a / 5 + count);
            return 0;
        }
    }

    if (a % 3 == 0)
    {
        printf("%d\n", a / 3);
        return 0;
    }

    printf("-1\n");

    return 0;
}