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

void init(struct PERSON *person, int *num, const char *name)
{
   FILE *myInFile;
   myInFile = fopen(name, "r");
   if (myInFile == NULL)
   {
      printf("Could not open %s!\n", name);
   }
   int count = 0;

   /* code here */
   while (fscanf(myInFile, "%s %d %s", person[count].name, &person[count].age, &person[count].hobby) != EOF)
   {
      count++;
   }

   fclose(myInFile);

   *num = count;
}

void grouping(struct PERSON *person, int num, int step, int start, int end, const char *name)
{
   int range_start = 0, range_end = 0;
   FILE *myOutFile;
   myOutFile = fopen(name, "w");
   if (myOutFile == NULL)
   {
      printf("Could not open %s!\n", name);
   }

   for (int j = start; j < end; j += step)
   {
      fprintf(myOutFile, "\nAge from %d to %d\n", j, j + step - 1);
      fprintf(myOutFile, "-------------------------------\n");
      /* code here */
      for (int i = 0; i < num; i++)
      {
         if (person[i].age >= j && person[i].age < j + step)
         {
            fprintf(myOutFile, "%s %d %s\n", person[i].name, person[i].age, person[i].hobby);
         }
      }
   }
   fclose(myOutFile);
}

int main()
{
   int count = 0, group_step = 0, start = 0, end = 0;
   struct PERSON person[MAX];

   // init person array: get information from file indicated
   init(person, &count, "personal.txt");

   // grouping and writing the result
   group_step = 10;
   start = 10;
   end = 50;

   grouping(person, count, group_step, start, end, "output.txt");

   return 0;
}