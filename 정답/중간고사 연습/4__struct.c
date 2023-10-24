#include <stdio.h>

#define NUM 3

struct PERSON
{
    char name[10];
    int age;
    float salary;
};

void init(struct PERSON *person)
{
    for (int i = 0; i < NUM; i++)
    {
        /* code here for initilization */
        scanf("%s %d %f", person[i].name, &person[i].age, &person[i].salary);
    }
}

void swap(struct PERSON *a, struct PERSON *b)
{
    struct PERSON tmp;
    /* code here for swapping */
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void sorting(struct PERSON *person)
{
    /* code here for sorting */
    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM - i; j++)
        {
            if ((person[i].age) > (person[j].age))
            {
                swap(&person[i], &person[j]);
            }
        }
    }
}

void print(struct PERSON *person)
{
    printf("\nPrinting the result\n");
    for (int i = 0; i < NUM; i++)
    {
        /* code here for printing */
        printf("%s %d %f\n", person[i].name, person[i].age, person[i].salary);
    }
}

int main()
{
    struct PERSON person[NUM];
    init(person);
    sorting(person);
    print(person);
    return 0;
}