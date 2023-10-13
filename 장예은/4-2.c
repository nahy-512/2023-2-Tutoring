/* Lab1-1: scratch */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NUM 5

struct FRUIT {
	/* code here for structure */
	char name[20];
	int price;
	int number;
};

void init(struct FRUIT* fru) {
	for (int i = 0; i < NUM; i++) {
		printf("Type %d-th info (name, price, number):", i);
		/* code here for initilization */
		scanf("%s %d %d", &fru[i].name, &fru[i].price, &fru[i].number);
	}
}

void print(struct FRUIT* fru) {
	int max=0;
	printf("\nPrinting the result\n");
	for (int i = 0; i < NUM; i++) {
		/* code here for printing */
		printf("%s Price= %d Number= %d Total=%d\n", fru[i].name, fru[i].price, fru[i].number, fru[i].price * fru[i].number);
		if (fru[max].price * fru[max].number < fru[i].price * fru[i].number)
			max = i;
	}
	printf("\nPrinting the most expensive item  in total\n");
	printf("%s Price= %d Number= %d Total=%d\n", fru[max].name, fru[max].price, fru[max].number, fru[max].price * fru[max].number);
}

int main() {
	struct FRUIT fru[NUM];
	init(fru);
	print(fru);
}