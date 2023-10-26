#include <stdio.h>

#define MAX 100000
#define MAX_NAME 100

struct Person
{
    int age;
    char name[MAX_NAME];
};

void swap(struct Person *, struct Person *);
void compareAge(int, struct Person *);
void printPerson(int, struct Person *);

int main()
{
    int N;
    scanf("%d", &N);
    struct Person person[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &person[i].age, person[i].name);
    }
    compareAge(N, person);
    // printf("=====================\n");
    printPerson(N, person);

    return 0;
}

void swap(struct Person *a, struct Person *b)
{
    struct Person temp;
    temp = *a;
    *a = *b;
    *b = temp;
    // printf("swap: %s %s\n", a->name, b->name);
}

void compareAge(int n, struct Person *person)
{
    /* bubble sort */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // 오름차순 정렬
            if (person[j].age > person[j + 1].age)
            {
                swap(&person[j], &person[j + 1]);
            }
        }
    }
}

void printPerson(int n, struct Person *person)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", person[i].age, person[i].name);
    }
}