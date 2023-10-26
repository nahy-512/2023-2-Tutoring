/* Lab1-2: scratch */
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
		printf("%s Price= %d Number= %d Total=%.5d\n", fru[i].name, fru[i].price, fru[i].number, fru[i].price * fru[i].number); // fru[i].price * fru[i].number
	}
}

void print_expensive_item(struct FRUIT* fru) {
	printf("\nPrinting the most expensive item in total\n");
	struct FRUIT tmp;
	int max_index, max_total;
	/* code here to find the most expensive in total */
	for (int i = 0; i < NUM; i++) {
		if ( i == 0 ) {
			max_index = i;
			max_total = fru[i].price * fru[i].number;
		}
		else if ( fru[i].price * fru[i].number > max_total) {
			max_index = i;
			max_total = fru[i].price * fru[i].number;
		}
	}
	/* code here for printing */
	printf("%s Price= %d Number= %d Total=%d\n", fru[max_index].name, fru[max_index].price, fru[max_index].number, max_total);
}

int main() {
	struct FRUIT fru[NUM];
	init(fru);
	print(fru);
	print_expensive_item(fru);
}