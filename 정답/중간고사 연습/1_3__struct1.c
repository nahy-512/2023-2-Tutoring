#include <stdio.h>
// 선언과 동시에 초기화

struct Birth
{
    int month;
    int day;
    int year;
} birth1 = {1, 1, 2001};

void changeYear(struct Birth *a, struct Birth *b)
{
    b->year = 2023;
    a->year = b->year;
    (*b).year = 2024;
}

int main()
{
    birth1.day = 2;

    struct Birth birth2;
    birth2.month = 2;
    birth2.day = 2;
    birth2.year = 2002;

    changeYear(&birth1, &birth2);
    printf("Birth1: %d/%d/%d\n", birth1.month, birth1.day, birth1.year);
    printf("Birth2: %d/%d/%d\n", birth2.month, birth2.day, birth2.year);

    return 0;
}