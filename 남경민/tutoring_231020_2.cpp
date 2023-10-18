#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct INFO{
	char name[10];
	int height;
	int weight;
	int schols;
};
int check_height(int he) {
	if (he < 180) {
		he = 180;
	}
	return he;
}
int check_weight(int we) {
	if (we < 100) {
		we = 100;
	}
	return we;
}

int main() {
	struct INFO student[5] = { 0 };
	for (int i = 0; i < 2; i++) {
		printf("Type %d-th student's info(Name, height, weight, schols): ", i);
		scanf("%s %d %d %d", &student[i].name, &student[i].height, &student[i].weight, &student[i].schols);
		student[i].height = check_height(student[i].height);
		student[i].weight = check_weight(student[i].weight);
	}
	printf("Name     =      %s\nHeight   =     %d\nWeight   =     %d\nSchols   =      %d\n", student[0].name, student[0].height, student[0].weight, student[0].schols);
	printf("\nName     =      %s\nHeight   =     %d\nWeight   =     %d\nSchols   =      %d\n", student[1].name, student[1].height, student[1].weight, student[1].schols);
}