#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    char str[81];  // 크기가 80인 char형 배열을 선언
    int score = 0; // 점수 계산
    int cons = 0;  // 연속 숫자 계산

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", str); // 표준 입력을 받아서 배열 형태의 문자열에 저장

        for (int j = 0; str[j] != '\0'; j++) // 한 줄의 문자열이 끝날 때까지 점수 계산
        {
            if (str[j] == 'O')
            {
                cons++;
                score += cons;
            }
            else
            {
                cons = 0;
            }
        }
        printf("%d\n", score); // 점수 출력
        score = 0;
        cons = 0;
    }

    return 0;
}
