//quickA+B.c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int a;
    int *input1, *input2;

    scanf("%d", &a);

    input1 = (int *)calloc(1, a * sizeof(int));
    input2 = (int *)calloc(1, a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        scanf("%d %d", &input1[i], &input2[i]);
    }

    for (int i = 0; i < a; i++)
    {
        printf("%d\n", input1[i] + input2[i]);
    }