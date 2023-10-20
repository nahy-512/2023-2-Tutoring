#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct INFO {
	char name[20];
	int height;
	double weight;
	int schols;
};

int main()
{
	struct INFO student[2];
	for (int i = 0; i < 2; i++)
	{
		printf("Type %d-th student's info (Name, Height, Weight, Schols): ",i);
		scanf("%s %d %lf %d",student[i].name,&student[i].height,&student[i].weight,&student[i].schols);
		if (student[i].height < 180)
			student[i].height = 180;
		if (student[i].weight < 100)
			student[i].height = 100.0;
	}
	for (int i = 0; i < 2; i++)
	{
		printf("Name\t=\t%s\n", student[i].name);
		printf("Height\t=\t%d\n", student[i].height);
		printf("Weight\t=\t%lf\n", student[i].weight);
		printf("Schols\t=\t%d\n\n", student[i].schols);
	}
	
	return 0;
}