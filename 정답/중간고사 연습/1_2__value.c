#include <stdio.h>

int n = 0;

void change1(int k)
{
    n = 1;
    k = 1;
}
void change2(int *k)
{
    n = 2;
    *k = 2;
}

int main()
{
    n = 4;
    int k = 4;
    change1(k);
    printf("%d %d\n", n, k);
    change2(&k);
    printf("%d %d\n", n, k);

    return 0;
}