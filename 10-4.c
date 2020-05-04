#include<stdio.h>
#include<stdlib.h>

struct listNode {
	char datum;
	struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

struct stackNode {
	int datum;
	struct stackNode * nextPtr;
};
typedef struct stackNode StackNode;
typedef struct stackNode * StackNodePtr;

void printStack(StackNodePtr currentPtr) {

	if (currentPtr == NULL) {
		printf("The stack is empty.\n\n");
	}
	else {
		while (currentPtr != NULL) {
			printf("%c ", currentPtr->datum);
			currentPtr = currentPtr->nextPtr;
		}
		printf("*\n\n");
	}
}

int isEmpty(ListNodePtr sPtr) {
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr) {
	if (currentPtr == NULL) {
		printf("List is empty.\n\n");
	}
	else {
		while (currentPtr != NULL) {
			printf("%c ", currentPtr->datum);
			currentPtr = currentPtr->nextPtr;
		}
		printf("*\n\n");
	}
}

void insert(ListNodePtr *sPtr, char value);
char delete_1(ListNodePtr *sPtr, char value);

char pop(ListNodePtr *topPtr) {
	ListNodePtr temp;
	int a;
	temp = (*topPtr);
	(*topPtr) = (*topPtr)->nextPtr;
	a = temp->datum;
	free(temp);
	return a;
}

void push(StackNodePtr *topPtr, char info) {
	StackNodePtr newPtr;
	newPtr = malloc(sizeof(StackNode));
	newPtr->datum = info;
	if ((*topPtr) == NULL) {
		(*topPtr) = newPtr;
		(*topPtr)->nextPtr = NULL;
		return;
	}
	newPtr->nextPtr = (*topPtr);
	(*topPtr) = newPtr;
}


int main(void) {
	ListNodePtr startPtr = NULL;
	StackNodePtr topPtr = NULL;
	int a;
	for (int j = 0; j<10; j++) {
		insert(&startPtr, 'A' + j);
	}
	printf("The list is: \n");
	printList(startPtr);
	while (!isEmpty(startPtr)) {
		a = pop(&startPtr);
		push(&topPtr, a);
	}
	printf("\nThe list in reverse is: \n");
	printStack(topPtr);
	return 0;
}

void insert(ListNodePtr *sPtr, char value) {
	ListNodePtr newPtr, currentPtr, previousPtr;
	newPtr = malloc(sizeof(ListNode));

	if ((*sPtr) == NULL) {
		(*sPtr) = newPtr;
		(*sPtr)->datum = value;
		(*sPtr)->nextPtr = NULL;
		return;
	}
	if (newPtr == NULL) {
		printf("There is no memory \n");
	}else {
		currentPtr = *sPtr;

		while (currentPtr != NULL && value>currentPtr->datum) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if (currentPtr != *sPtr) {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
			newPtr->datum = value;
		}else {
			(*sPtr) = newPtr;
			(*sPtr)->nextPtr = currentPtr;
			(*sPtr)->datum = value;
		}
	}
}

char delete_1(ListNodePtr *sPtr, char value) {
	ListNodePtr currentPtr, previousPtr;
	char temp;
	currentPtr = *sPtr;

	while (currentPtr != NULL && currentPtr->datum != value) {
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}
	if (currentPtr == NULL) {
		return -1;
	}else {
		if (currentPtr != (*sPtr)) {
			previousPtr->nextPtr = currentPtr->nextPtr;
			temp = currentPtr->datum;
			free(currentPtr);
			return temp;
		}else {
			(*sPtr) = currentPtr->nextPtr;
			temp = currentPtr->datum;
			free(currentPtr);
			return temp;
		}
	}
}








