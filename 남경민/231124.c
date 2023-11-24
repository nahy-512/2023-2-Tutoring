#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 10

struct PERSON {
    char name[20];
    int age;
    char hobby[20];
};

struct PERSON_A {
    char name[20];
    int age;
};

struct PERSON_B {
    char name[20];
    char hobby[20];
};


void init(struct PERSON* person, int* num, const char* name) {
    FILE* myInFile;
    myInFile = fopen(name, "r");
    if (myInFile == NULL) {
        printf("Could not open %s!\n", name);
    }
    int count = 0;
    while (fscanf(myInFile, "%s %d %s", &person[count].name, &person[count].age, &person[count].hobby) != EOF) {
        count++;
    }
    fclose(myInFile);

    *num = count;
}

void gen_person_a(struct PERSON* src, struct PERSON_A* dst, int num) {
    for (int i = 0; i < num; i++) {
        strcpy(dst[i].name, src[i].name);
        dst[i].age = src[i].age;
    }
}

void gen_person_b(struct PERSON* src, struct PERSON_B* dst, int num) {
    for (int i = 0; i < num; i++) {
        strcpy(dst[i].name, src[i].name);
        strcpy(dst[i].hobby, src[i].hobby);
    }
}

void write_person_a(struct PERSON_A* src, int num, const char* name) {
    FILE* OutFile = fopen(name, "w");
    if (OutFile == NULL) {
        printf("Could not open %s!\n", name);
        return;
    }

    for (int i = 0; i < num; i++) {
        fprintf(OutFile, "%s %d\n", src[i].name, src[i].age);
    }

    fclose(OutFile);
}

void write_person_b(struct PERSON_B* src, int num, const char* name) {
    FILE* OutFile = fopen(name, "w");
    if (OutFile == NULL) {
        printf("Could not open %s!\n", name);
        return;
    }

    for (int i = 0; i < num; i++) {
        fprintf(OutFile, "%s %s\n", src[i].name, src[i].hobby);
    }

    fclose(OutFile);
}

void main() {
    int count = 0;
    struct PERSON person[MAX];
    struct PERSON_A person_a[MAX];
    struct PERSON_B person_b[MAX];

    // init person array: get information from file indicated
    init(person, &count, "personal.txt");

    // generation PERSON_A
    gen_person_a(person, person_a, count);

    // write a file for PERSON_A
    write_person_a(person_a, count, "age.txt");

    // generation PERSON_B
    gen_person_b(person, person_b, count);

    // write a file for PERSON_B
    write_person_b(person_b, count, "hobby.txt");
    
    return 0;
}
