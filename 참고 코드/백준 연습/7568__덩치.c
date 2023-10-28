/* 3주차 과제 문제 */
#include <stdio.h>

#define MAX 50

struct Person
{
    int weight; // 몸무게
    int height; // 키
    int rank;   // 덩치 등수
};

void compareBuild(int, struct Person *);

int main()
{
    int N;
    scanf("%d", &N);
    struct Person person[50];

    // 입력 받기
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &person[i].weight, &person[i].height);
        person[i].rank = 1; // 랭크를 모두 1으로 초기화
    }
    // 덩치 비교
    compareBuild(N, person);
    // 결과 출력
    for (int i = 0; i < N; i++)
    {
        printf("%d ", person[i].rank);
    }

    return 0;
}

void compareBuild(int n, struct Person *person)
{
    // 덩치가 가장 큰 사람이 덩치 등수 1등
    // 굳이 정렬하지 않아도 됨
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (person[i].weight < person[j].weight && person[i].height < person[j].height)
            {
                person[i].rank++;
            }
        }
    }
}