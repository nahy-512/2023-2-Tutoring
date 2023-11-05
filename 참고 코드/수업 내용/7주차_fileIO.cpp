#include <stdio.h>

void writeData(const char *);
void readData(const char *);

int main()
{
    char fileName[20] = "data.txt";

    writeData(fileName);
    readData(fileName);

    return 0;
}

void writeData(const char *fileName)
{
    FILE *outFile = fopen(fileName, "w");

    if (outFile == NULL)
    {
        printf("Output File Could Not be Opened");
        return;
    }
    int numbers[] = {5, 96, 87, 78, 93, 21, 4, 92, 82, 85, 87, 6, 72, 69, 85, 75, 81, 73};
    int num_count = sizeof(numbers) / sizeof(numbers[0]);

    // 숫자를 파일에 저장
    for (int i = 0; i < num_count; i++)
    {
        fprintf(outFile, "%d ", numbers[i]);
    }

    fclose(outFile);
}

void readData(const char *fileName)
{
    FILE *inFile = fopen(fileName, "r");
    int N;

    if (inFile == NULL)
    {
        printf("Input File Could Not be Opened");
        return;
    }

    int num;
    int group_sum = 0;

    while (fscanf(inFile, "%d", &num) != EOF)
    {
        printf("%d -> ", num);

        for (int i = 0; i < num; i++)
        {
            int value;
            fscanf(inFile, "%d", &value);
            group_sum += value;
            printf("%d ", value);
        }

        printf("/ Group Average: %d\n", group_sum / num);
        group_sum = 0;
    }

    // while (fscanf(inFile, "%d", N) != EOF)
    // {
    //     int sum = 0;
    //     for (int i = 1; i <= N; i++)
    //     {
    //         int value;
    //         fscanf(inFile, "%d", value);
    //         sum += value;
    //     }
    //     printf("sum = %d\n", sum);
    // }

    fclose(inFile);
}