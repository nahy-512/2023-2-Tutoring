#include <stdio.h>
#include <string.h>
#define MAX 10

struct PERSON
{
    char name[20];
    int age;
    float salary;
};

void read_data(struct PERSON *person, int *num, const char *file_name)
{
    FILE *myInFile;
    myInFile = fopen(file_name, "r");
    if (myInFile == NULL)
    {
        printf("Could not open %s!\n", file_name);
    }
    int count = 0;
    while (fscanf(myInFile, "%s %d %f", person[count].name, &person[count].age, &person[count].salary) != EOF)
    {
        count++;
    }
    fclose(myInFile);
    *num = count;
}

void write_data(struct PERSON *src, int num, const char *file_name)
{
    FILE *myOutFile;
    myOutFile = fopen(file_name, "w");
    if (myOutFile == NULL)
    {
        printf("Could not open %s!\n", file_name);
    }
    for (int i = 0; i < num; i++)
    {
        fprintf(myOutFile, "%s %d %.1f\n", src[i].name, src[i].age, src[i].salary);
    }

    fclose(myOutFile);
}

void update_data(struct PERSON *src, int num, int age_start, int age_end, float percent)
{
    for (int i = 0; i < num; i++)
    {
        if (src[i].age >= age_start && src[i].age <= age_end)
        {
            src[i].salary *= (1 + percent);
        }
    }
}

int main()
{
    int count = 0;
    struct PERSON person[MAX];

    // read data from salary_v1.txt
    read_data(person, &count, "salary_v1.txt");

    // update data based on the age
    update_data(person, count, 40, 49, 0.1);
    // write a file for salary_v2.txt
    write_data(person, count, "salary_v2.txt");

    // read data from salary_v2.txt
    read_data(person, &count, "salary_v2.txt");

    // update data based on the age and raised percent
    update_data(person, count, 30, 39, 0.2);
    // write a file for salary_v3.txt
    write_data(person, count, "salary_v3.txt");

    return 0;
}