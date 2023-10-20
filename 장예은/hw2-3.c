#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct INFO {
	char name[20];
	int height;
	double weight;
	int schols;
};

void change(struct INFO*);

int main()
{
	struct INFO student[2];
	for (int i = 0; i < 2; i++)
	{
		printf("Type %d-th student's info (Name, Height, Weight, Schols): ", i);
		scanf("%s %d %lf %d", student[i].name, &student[i].height, &student[i].weight, &student[i].schols);
	}
	change(student);
	return 0;
}
void change(struct INFO inform[]) 
{
	
	for (int i = 0; i < 2; i++)
	{
		if (inform[i].height < 180)
			inform[i].height = 180;
		if (inform[i].weight < 100)
			inform[i].height = 100.0;
		printf("Name\t=\t%s\n", inform[i].name);
		printf("Height\t=\t%d\n", inform[i].height);
		printf("Weight\t=\t%lf\n", inform[i].weight);
		printf("Schols\t=\t%d\n\n", inform[i].schols);
	}
}