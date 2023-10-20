#include <stdio.h>

struct NODE {
	int key;
	int* next;
};
int main()
{
	struct NODE index[5];
	printf("beford linking\n");
	for (int i = 0; i < 5; i++)
	{
		index[i].key = i;
		index[i].next = 0;
		int* address = &index[i];
		printf("index=%d key=%d next=%d Add=%d\n", i, index[i].key, index[i].next,address);
	}
	for (int i = 0; i < 4; i++)
	{
		index[i].next = &index[i + 1];
	}
	printf("\nafter linking\n");
	for (int i = 0; i < 5; i++)
	{
		printf("index=%d key=%d next=%d Add=%d\n", i, index[i].key, index[i].next,&index[i]);
	}
	return 0;
}