#include <stdio.h>

int n = 0;

void change1(int k)
{
    n = 1;
    k = 1;
    // printf("change1: %d\n", n);
}

void change2(int *k)
{
    n = 2;
    *k = 2;
    // printf("change2: %d\n", *n);
}

int main()
{
    n = 4;
    int k = 4;
    
    change1(k);
    printf("%d %d\n", n, k);

    change2(&k);
    printf("%d %d\n", n, k);
}