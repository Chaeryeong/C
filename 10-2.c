#include<stdio.h>
#include<stdlib.h>

struct listNode {
	int data;
	struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;
void insert(ListNodePtr *sPtr, int value) {
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	newPtr = malloc(sizeof(ListNode));

	if (newPtr != NULL) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && value > currentPtr->data) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}else {
		printf("%c not inserted. No memory available.\n", value);
	}
}

void printList(ListNodePtr currentPtr) {
	if (currentPtr == NULL) {
		printf("List is empty.\n\n");
	}else {
		while (currentPtr != NULL) {
			printf("%d ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("*\n\n");
	}
}
ListNodePtr merge(ListNodePtr sPtr1, ListNodePtr sPtr2);

int main(void) {

	ListNodePtr startPtr1 = NULL, startPtr2 = NULL;
	int it;

	for (it = 2; it <= 10; it += 2)
	{
		insert(&startPtr1, it);
	}
	for (it = 1; it <= 9; it += 2)
	{
		insert(&startPtr2, it);
	}

	printf("List 1 is: ");
	printList(startPtr1);
	printf("List 2 is: ");
	printList(startPtr2);
	merge(startPtr1, startPtr2);

	return 0;
}

ListNodePtr merge(ListNodePtr sPtr1, ListNodePtr sPtr2)
{
	ListNodePtr newPtr = NULL, currentPtr;
	currentPtr = sPtr1;

	while (currentPtr != NULL) {
		insert(&newPtr, currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
	currentPtr = sPtr2;
	while (currentPtr != NULL) {
		insert(&newPtr, currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}

	printf("The merged list is: ");
	printList(newPtr);

	return newPtr;
}

