/* Lab1-3: scratch */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NUM 5

struct FRUIT
{
	/* code here for structure */
	char name[10];
	int price;
	int number;
};

void init(struct FRUIT *fru)
{
	for (int i = 0; i < NUM; i++)
	{
		printf("Type %d-th info (name, price, number):", i);
		/* code here for initilization */
		scanf("%s %d %d", fru[i].name, &fru[i].price, &fru[i].number);
	}
}

void swap(struct FRUIT *a, struct FRUIT *b)
{
	/* code here for swapping */
	struct FRUIT tmp;
	printf("swap\n");
	tmp = *a;
	*a = *b;
	*b = tmp;
	printf("%s(%d) <-> %s(%d)\n\n", a->name, (a->number * a->price), b->name, (b->number * b->price));
}

void sorting(struct FRUIT *fru)
{
	/* code here for sorting */
	for (int i = 0; i < NUM; i++)
	{
		for (int j = i + 1; j < NUM; j++)
		{
			if ((fru[i].price * fru[i].number) < (fru[j].price * fru[j].number))
			{
				printf("[i],[j]: %d %d\n", i, j);
				swap(&fru[i], &fru[j]);
			}
		}
	}
}
// void sorting(struct FRUIT *fru)
// {
// 	/* code here for sorting */
// 	// 내림차순 정렬
// 	for (int i = 0; i < NUM; i++)
// 	{
// 		for (int j = i + 1; i < NUM; j++)
// 		{
// 			if ((fru[i].price * fru[i].number) < (fru[j].price * fru[j].number))
// 				swap(&fru[i], &fru[j]);
// 		}
// 	}
// }
void print(struct FRUIT *fru)
{
	printf("\nPrinting the result\n");
	for (int i = 0; i < NUM; i++)
	{
		/* code here for printing */
		printf("%s Price= %d Number= %d Total=%d\n", fru[i].name, fru[i].price, fru[i].number, fru[i].price * fru[i].number);
	}
}

int main()
{
	struct FRUIT fru[NUM];
	init(fru);
	sorting(fru);
	print(fru);
}