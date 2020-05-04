#include<stdio.h>
#include<stdlib.h>

struct listNode {
	int data;
	struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;
void instructions(void) {

	printf("Etner your choice:\n"
		"	1 to insert an element into the list.\n"
		"	2 to recursively search list for an element.\n"
		"	3 to recursively outputs the element in a list in reverse order.\n"
		"	4 to end.\n");
}
void printListBackwards(ListNodePtr currentPtr)
{
	if (currentPtr == NULL)
		return;

	printListBackwards(currentPtr->nextPtr);
	printf("%d ", currentPtr->data);
}
void insert(ListNodePtr *sPtr, int value);
void printList(ListNodePtr currentPtr);
ListNodePtr searchList(ListNodePtr sPtr, int value);

int main(void) {
	ListNodePtr startPtr = NULL;
	int selection, it;

	instructions();
	printf("? ");
	scanf_s("%d", &selection);

	while (selection != 4) {
		switch (selection) {
		case 1:
			printf("Enter a integer: ");
			scanf_s("%d", &it);
			insert(&startPtr, it);
			printList(startPtr);
			break;

		case 2:
			printf("Enter integer to recursively search for: ");
			scanf_s("%d", &it);
			if (searchList(startPtr, it))
			{
				printf("%d is in the list.\n\n", it);
			}else
				printf("%d is not in the list.\n\n", it);
			break;

		case 3:
			printListBackwards(startPtr);
			printf("\n\n");
			break;

		default:
			printf("Invalid choice.\n\n");
			instructions();
			break;
		}
		printf("? ");
		scanf_s("%d", &selection);
	}
	printf("End of run.\n");
	return 0;
}

ListNodePtr searchList(ListNodePtr sPtr, int value)
{
	if (sPtr == NULL)
		return NULL;
	else if (sPtr->data == value)
		return sPtr;
	else
		return searchList(sPtr->nextPtr, value);
}

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
		printf("The list is:\n");
		while (currentPtr != NULL) {
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}