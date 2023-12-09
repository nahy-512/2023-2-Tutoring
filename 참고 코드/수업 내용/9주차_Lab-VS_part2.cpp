#include <stdio.h>
#include <string.h>
#define MAX 10

struct PERSON {
    char name[20];
    int age;
    float salary;
};

void read_data(struct PERSON* person, int* num, const char* file_name) {
    FILE* myInFile;
    myInFile = fopen(file_name, "r");
    if (myInFile == NULL ) {
        printf("Could not open %s!\n", file_name);
    }
    int count = 0;
    while (fscanf(myInFile, "%s %d %f", person[count].name, &person[count].age, &person[count].salary) != EOF) {
        count++;
    }
    fclose(myInFile);
    *num = count;
}

void print_result(struct PERSON* a, struct PERSON* b, int num) {
    for (int i = 0; i < num; i++) {
        printf("\t%-8s %3d %8.1f -> %8.1f\n", a[i].name, a[i].age, a[i].salary, b[i].salary);
    }
}

int main() {
    int count = 0;
    struct PERSON person_a[MAX];
    struct PERSON person_b[MAX];

    // read data from salary_v1.txt
    read_data(person_a, &count, "salary_v1.txt");
    // read data from salary_v3.txt
    read_data(person_b, &count, "salary_v3.txt");

    // print difference
    print_result(person_a, person_b, count);

    return 0;
}