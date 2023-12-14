#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 5

struct NODE
{
    char name[20];
    struct NODE *next;
};

struct NODE *createNewNode(char *name)
{
    /* (A) Code here */
    struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

int searchKey(struct NODE *head, const char *name)
{
    /* (B) Code here */
    struct NODE *pNode = head;
    while (pNode != NULL)
    {
        if (strcmp(pNode->name, name) == 0)
            return 1;
        pNode = pNode->next;
    }
    return 0;
}

void searchTest(struct NODE *head, const char *name)
{
    int found = searchKey(head, name);
    if (found)
        printf("search key(%s) found\n\n", name);
    else
        printf("search key(%s) not found\n\n", name);
}

void addNode(struct NODE *head, struct NODE *node)
{
    /* (C) Code here */
    struct NODE *cNode = head;
    struct NODE *pNode = NULL;
    while (cNode != NULL)
    {
        if (strcmp(cNode->name, node->name) > 0)
            break;
        pNode = cNode;
        cNode = cNode->next;
    }
    node->next = cNode;
    pNode->next = node;
}

void displayList(struct NODE *head)
{
    /* (D) Code here */
    struct NODE *ptr = head;
    while (ptr != NULL)
    {
        printf("[%s] --> ", ptr->name);
        ptr = ptr->next;
    }
    printf("[NULL]\n\n");
}

int main()
{
    int i = 0;
    char names[NUM][20] = {"AA", "BB", "CC", "DD", "EE"};
    struct NODE *head, *tmp;

    // Initialize node
    head = createNewNode(names[0]);
    for (i = 1; i < NUM; i++)
    {
        tmp = createNewNode(names[i]);
        addNode(head, tmp);
    }
    displayList(head);

    // search node
    searchTest(head, "AA");
    searchTest(head, "FF");

    return 0;
}