#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10
#define NUM_CITY 3
#define NUM_GENDER 2
#define RANGE_AGE 70

const char *gender[NUM_GENDER] = {"Male", "Female"};
const char *city[NUM_CITY] = {"Seoul", "Busan", "Daegu"};

struct PERSON
{
    char city[20];
    char gender[20];
    int age;
};

void generation(const char *fileName)
{
    int tmp_city, tmp_age, tmp_gender;
    FILE *myOutFile;

    // Open a file stream for writing
    /* (A) Code here */
    myOutFile = fopen(fileName, "w");
    if (myOutFile == NULL)
    {
        printf("Could not open %s!\n", fileName);
    }

    srand(time(NULL));

    // Generate random samples and save them to opened file
    /* (B) Code here */
    for (int i = 0; i < MAX; i++)
    {
        tmp_city = rand() % NUM_CITY;
        tmp_gender = rand() % NUM_GENDER;
        tmp_age = rand() % RANGE_AGE + 10;
        fprintf(myOutFile, "%s %s %d\n", city[tmp_city], gender[tmp_gender], tmp_age);
    }

    fclose(myOutFile);
}

void read(struct PERSON *p, int num, const char *fileName)
{
    FILE *myInFile;

    // Open a file stream for reading and read data from the opened file
    /* (C) Code here */
    myInFile = fopen(fileName, "r");
    if (myInFile == NULL)
    {
        printf("Could not open %s!\n", fileName);
    }

    for (int i = 0; i < num; i++)
    {
        fscanf(myInFile, "%s %s %d", p[i].city, p[i].gender, &p[i].age);
    }
    fclose(myInFile);
}

int num_count(struct PERSON *p, int num, const char *gender, const char *city)
{
    int count = 0;

    // Count the number of elements which meet the condition
    /* (D) Code here */
    for (int i = 0; i < num; i++)
    {
        if (p[i].age >= 10 && p[i].age < 20 && strcmp(p[i].gender, gender) == 0 && strcmp(p[i].city, city) == 0)
            count++;
    }
    return count;
}

int main()
{
    struct PERSON person[MAX];
    int num = MAX, count = 0;
    const char *fileName = "information.txt";

    // generate of text file
    generation(fileName);

    // read person array
    read(person, num, fileName);

    // count the number of people in the given condition
    count = num_count(person, num, gender[1], city[0]);
    printf("The number of female teenages in Seoul: %d\n", count);

    return 0;
}