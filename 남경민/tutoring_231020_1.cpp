#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct NODE{
	int key;
	struct NODE* next; /*struct NODE* ���� int* ���� ������ ���� ���°��̰���? (25�� ����)*/
}array[5];
struct INDEX {
	int key;
	int num;
}index[5];

int main() {
	struct NODE array[5]={{0,0}, {1,0}, {2,0}, {3,0}, {4,0}};
	printf("Before linking\n");
	for (int i = 0; i < 5; i++) {
		index[i].key = array[i].key;
		index[i].num = i;
		/*key*/
		/*�ٵ� �� �ε����� ������ �𸣰���. �� �϶�� �� �ɱ�?*/
		printf("i=%d key=%d next=%d Add=%d\n", i, array[i].key, array[i].next, &array[i]);
	}
	/*before node link*/
	printf("\nAfter linking\n");
	for (int i = 0; i < 5; i++) {
		if (i != 4) {
			array[i].next = &array[i + 1];
		}
		printf("i=%d key=%d next=%d Add=%d\n", i, array[i].key, array[i].next, &array[i]);
	}
	/*After node link */
}