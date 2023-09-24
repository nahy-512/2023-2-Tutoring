#include <stdio.h>
#include <string.h> // strcat 함수가 선언된 헤더 파일

int main()
{
    int n;
    char star[101];
    scanf("%d", &n);
    if (n < 1 || n > 100)
        return 1;
    printf("int a;\n");
    for (int i = 1; i <= n; i++)
    {
        strcat(star, "*"); // star 뒤에 * 하나를 더 붙임
        if (i == 1)
        {
            printf("int *ptr = &a;");
        }
        else
        {
            if (i == 2)
                printf("\nint %sptr%d = &ptr;\n", star, i);
            else
                printf("int %sptr%d = &ptr%d;\n", star, i, i - 1);
        }
    }
    return 0;
}