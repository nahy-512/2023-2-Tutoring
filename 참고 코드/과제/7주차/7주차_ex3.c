#include <stdio.h>
#include <string.h>

#define MAX 5
#define LINE_MAX 50

void readAndWrite(const char *, const char *);

int main()
{
    // 데이터 읽고 쓰기
    readAndWrite("employee.dat", "employee.bak");

    return 0;
}

void readAndWrite(const char *infileName, const char *outFileName)
{
    FILE *inFile = fopen(infileName, "r");
    FILE *outFile = fopen(outFileName, "w");

    if (inFile == NULL)
    {
        printf("Input File Could Not be Opened");
        return;
    }

    if (outFile == NULL)
    {
        printf("Output File Could Not be Opened");
        return;
    }

    char line[LINE_MAX];
    while (fgets(line, LINE_MAX, inFile) != NULL)
    {
        fprintf(outFile, "%s", line);
    }

    fclose(inFile);
}