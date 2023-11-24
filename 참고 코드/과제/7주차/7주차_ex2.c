#include <stdio.h>
#include <string.h>

#define MAX 4

struct CAR
{
    char name[20];
    int year;
    double price;
} car[MAX] = {{"Avante", 2007, 13000.00}, {"Sonata", 2008, 18000.00}, {"SM7", 2009, 22000.00}, {"Equus", 2010, 35000.00}};

void initData(struct CAR *car);
void writeData(const char *, struct CAR *);
void readData(const char *);

int main()
{
    char fileName[20] = "cars.txt";

    // initData(car);
    // 데이터 쓰기
    writeData(fileName, car);
    // 쓴 데이터 읽기
    readData(fileName);

    return 0;
}

void initData(struct CAR *car)
{
    // 구조체 배열 초기화
    strcpy(car[0].name, "Avante");
    car[0].year = 2007;
    car[0].price = 13000.00;

    strcpy(car[1].name, "Sonata");
    car[1].year = 2008;
    car[1].price = 18000.00;

    strcpy(car[2].name, "SM7");
    car[2].year = 2009;
    car[2].price = 22000.00;

    strcpy(car[3].name, "Equus");
    car[3].year = 2010;
    car[3].price = 35000.00;
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
        fprintf(outFile, "%s %d %lf\n", car[i].name, car[i].year, car[i].price);
    }

    fclose(outFile);
}

void readData(const char *fileName)
{
    FILE *inFile = fopen(fileName, "r");
    char name[20];
    int year;
    double price;

    if (inFile == NULL)
    {
        printf("Input File Could Not be Opened");
        return;
    }

    int i = 0;
    printf("--------------------------\n");
    printf("|Name\t|Year\t|Price\t|\n");
    printf("--------------------------\n");
    while (fscanf(inFile, "%s %d %lf", name, &year, &price) != EOF)
    {
        printf("|%s\t|%d\t|%.2lf|\n", name, year, price);
        i++;
    }
    printf("--------------------------");

    fclose(inFile);
}