#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NUM 5

struct NODE {
	int key;
	struct NODE* next;
};

struct NODE* createNewNode(int key) {
	struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
	if (newNode == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->key = key;
	newNode->next = NULL;
	return newNode;
}

int searchKey(struct NODE* head, int srchkey) {
	while (head != NULL) {
		if (head->key == srchkey) {
			return 1;  // Key found
		}
		head = head->next;
	}
	return 0;  // Key not found
}

void searchTest(struct NODE* head, int key) {
	int found = searchKey(head, key);
	if (found)
		printf("search key(%d) found\n\n", key);
	else
		printf("search key(%d) not found\n\n", key);
}

void addNode(struct NODE* head, struct NODE* node) {
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = node;
}

void deleteNode(struct NODE* head, int key) {
	struct NODE* current = head;
	struct NODE* previous = NULL;
	while (current != NULL && current->key != key) {
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		printf("Key %d not found for deletion\n", key);
		return;
	}
	if (previous != NULL) {
		previous->next = current->next;
	}
	free(current);
}

void displayList(struct NODE* head) {
	while (head != NULL) {
		printf("[%d] --> ", head->key);
		head = head->next;
	}
	printf("[NULL]\n");
}

void main() {
	int i = 0;
	struct NODE* head;
	struct NODE* tmp;

	// Initialize node
	head = createNewNode(0);
	for (i = 1; i < NUM; i++) {
		tmp = createNewNode(i);
		addNode(head, tmp);
	}
	displayList(head);

	// Add node
	tmp = createNewNode(50);
	addNode(head, tmp);
	tmp = createNewNode(30);
	addNode(head, tmp);
	displayList(head);

	// Search node
	searchTest(head, 5);
	searchTest(head, 4);
	searchTest(head, 30);

	// Delete node
	deleteNode(head, 3);
	deleteNode(head, 30);
	displayList(head);

	// Add node
	tmp = createNewNode(7);
	addNode(head, tmp);
	displayList(head);
}