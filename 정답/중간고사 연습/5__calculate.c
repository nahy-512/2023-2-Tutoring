#include <stdio.h>

void calculate(int *n1, int *n2, int *r1, int *r2, int *r3, int *r4)
{
    *r1 = *n1 * *n2;
    *r2 = *n1 / *n2;
    *r3 = *n1 % *n2;
    *r4 = *n1 + *n2;
}

int main()
{
    int N1, N2, re1 = 0, re2 = 0, re3 = 0, re4 = 0;
    scanf("%d %d", &N1, &N2);
    calculate(&N1, &N2, &re1, &re2, &re3, &re4);
    printf("%d %d %d %d", re1, re2, re3, re4);

    return 0;
}