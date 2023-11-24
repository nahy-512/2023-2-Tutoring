#include <stdio.h>
#include <string.h>

#define MAX 2

struct CAR
{
    char name[20];
    int year;
} car[MAX] = {{"Avante", 2007}, {"Sonata", 2008}};

void writeData(const char *, struct CAR *);
void readData(const char *);

int main()
{
    char fileName[20] = "cars.txt";

    // 데이터 쓰기
    writeData(fileName, car);
    // 쓴 데이터 읽기
    readData(fileName);

    return 0;
}

void writeData(const char *fileName, struct CAR *car)
{
    FILE *outFile = fopen(fileName, "w");

    if (outFile == NULL)
    {
        printf("Output File Could Not be Opened");
        return;
    }

    // 배열을 파일에 저장
    for (int i = 0; i < MAX; i++)
    {
        fprintf(outFile, "%s %d\n", car[i].name, car[i].year);
    }

    fclose(outFile);
}

void readData(const char *fileName)
{
    FILE *inFile = fopen(fileName, "r");
    char name[20];
    int year;

    if (inFile == NULL)
    {
        printf("Input File Could Not be Opened");
        return;
    }

    int i = 0;
    while (fscanf(inFile, "%s %d", name, &year) != EOF)
    {
        printf("%s\t%d\n", name, year);
        i++;
    }

    fclose(inFile);
}