#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 10

struct PERSON
{
   char name[20];
   int age;
   char hobby[20];
};

struct PERSON_A
{
   char name[20];
   int age;
};

struct PERSON_B
{
   char name[20];
   char hobby[20];
};

void init(struct PERSON *person, int *num, const char *name)
{
   FILE *myInFile;
   myInFile = fopen(name, "r");
   if (myInFile == NULL)
   {
      printf("Could not open %s!\n", name);
   }
   int count = 0;
   while (fscanf(myInFile, "%s %d %s", person[count].name, &person[count].age, person[count].hobby) != EOF)
   {
      count++;
   }
   fclose(myInFile);

   *num = count;
}

void gen_person_a(struct PERSON *src, struct PERSON_A *dst, int num)
{
   for (int i = 0; i < num; i++)
   {
      /* code here*/
      strcpy(dst[i].name, src[i].name);
      dst[i].age = src[i].age;
   }
}

void gen_person_b(struct PERSON *src, struct PERSON_B *dst, int num)
{
   for (int i = 0; i < num; i++)
   {
      /* code here*/
      strcpy(dst[i].name, src[i].name);
      strcpy(dst[i].hobby, src[i].hobby);
   }
}

void write_person_a(struct PERSON_A *src, int num, const char *name)
{
   /* code here*/
   FILE *myOutFile;
   myOutFile = fopen(name, "w");
   if (myOutFile == NULL)
   {
      printf("Could not open %s", name);
   }
   for (int i = 0; i < num; i++)
   {
      fprintf(myOutFile, "%s %d\n", src[i].name, src[i].age);
   }
   fclose(myOutFile);
}

void write_person_b(struct PERSON_B *src, int num, const char *name)
{
   /* code here*/
   FILE *myOutFile;
   myOutFile = fopen(name, "w");
   for (int i = 0; i < num; i++)
   {
      fprintf(myOutFile, "%s %s\n", src[i].name, src[i].hobby);
   }
   fclose(myOutFile);
}

int main()
{
   int count = 0;
   struct PERSON person[MAX];     // personal.txt에서 읽은 값 저장
   struct PERSON_A person_a[MAX]; // 이름 & 나이만 저장
   struct PERSON_B person_b[MAX]; // 이름 & 취미만 저장

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
