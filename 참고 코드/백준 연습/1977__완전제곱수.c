/* 2주차 과제 문제 */
#include <stdio.h>

int returnPerfectSquareNum(int n, int *);

int main()
{
    int start;
    int end;
    scanf("%d", &start);
    scanf("%d", &end);
    int min = -1;
    int sum = 0;

    for (int i = start; i <= end; i++)
    {
        if (returnPerfectSquareNum(i, &min) != -1)
        {
            // 완전제곱수 더하기
            sum += i;
        }
    }
    if (min == -1)
        printf("-1");
    else
        printf("%d\n%d", sum, min);
    return 0;
}

int returnPerfectSquareNum(int num, int *min)
{
    for (int j = 1; j <= num; j++)
    { // 완전제곱수인지 판별하기
        if (num == j * j)
        { // 완전제곱수
            if (*min == -1)
            {
                // 완전제곱수 최솟값 저장
                *min = num;
            }
            return num; // 완전제곱수
        }
    }
    return -1;
}