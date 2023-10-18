#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct NODE{
	int key;
	struct NODE* next; /*struct NODE* 말고 int* 으로 설정할 수는 없는것이겠지? (25줄 참고)*/
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
		/*근데 왜 인덱싱한 것인지 모르겠음. 왜 하라고 한 걸까?*/
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