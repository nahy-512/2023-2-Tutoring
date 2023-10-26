/* Lab1-1: scratch */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NUM 5

struct FRUIT {
	/* code here for structure */
	char name[10];
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
	printf("\nPrinting the result\n");
	for (int i = 0; i < NUM; i++) {
		/* code here for printing */
		printf("%s Price= %d Number= %d Total=%d\n", fru[i].name, fru[i].price, fru[i].number, fru[i].price * fru[i].number);
	}
}

int main() {
	struct FRUIT fru[NUM];
	init(fru);
	print(fru);
}