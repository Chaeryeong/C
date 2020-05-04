#include <stdio.h>
#include <stdlib.h>

struct queueNode {
	char data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode* QueueNodePtr;

void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr *headPtr);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);

void printQueue(QueueNodePtr currentPtr)
{
	if (currentPtr == NULL) {
		printf("Queue is empty.\n\n");
	}
	else {
		printf("The queue is :\n");

		while (currentPtr != NULL) {
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");


	}


}

int isEmpty(QueueNodePtr *headPtr)
{
	return headPtr == NULL;
}

char dequeue(QueueNodePtr * headPtr, QueueNodePtr * tailPtr)
{
	char value;
	QueueNodePtr temp_Ptr;

	value = (*headPtr)->data;
	temp_Ptr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
		*tailPtr = NULL;
	
	free(temp_Ptr);

	return value;
}

void enqueue(QueueNodePtr * headPtr, QueueNodePtr * tailPtr, char value)
{
	QueueNodePtr new_Ptr;

	new_Ptr = malloc(sizeof(QueueNode));

	if (new_Ptr != NULL)
	{
		new_Ptr->data = value;
		new_Ptr->nextPtr = NULL;

		if (isEmpty(*headPtr)) {
			*headPtr = new_Ptr;
		}else 
			(*tailPtr)->nextPtr = new_Ptr;
		*tailPtr = new_Ptr;
	}
	else 
		printf("%c not inserted. No memory available.\n", value);
}

int main(void) {
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	int choice;
	char item;

	printf("Enter your choice:\n");
	printf("	1 to add an item to the queue\n");
	printf("	2 to remove an item from the queue\n");
	printf("	3 to end\n");
	printf("? ");
	scanf_s("%d", &choice);

	while (choice != 3) {
		switch (choice)
		{

		case 1:
			printf("Enter a character: ");
			scanf_s("\n%c", &item, 1);
			enqueue(&headPtr, &tailPtr, item);
			printQueue(headPtr);
			break;
		case 2:
			if (!isEmpty(headPtr)) {
				item = dequeue(&headPtr, &tailPtr);
				printf("%c has been dequeued.\n", item);
			}
			printQueue(headPtr);
			break;

		default:
			printf("Invalid choice.\n\n");
			printf("Enter your choice:\n");
			printf("	1 to add an item to the queue\n");
			printf("	2 to remove an item from the queue\n");
			printf("	3 to end\n");
			break; 
		}
		printf("? ");
		scanf_s("%d", &choice);


	}
	printf("End of run.\n");
	return 0;

}