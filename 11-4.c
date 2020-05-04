#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct TreeNode {
	struct TreeNode *leftPtr;
	int data;
	struct TreeNode *rightPtr;
};

typedef struct TreeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void levelOrderTraversal(TreeNodePtr treePtr);


struct QueueNode {
	TreeNodePtr data;
	struct QueueNode *nextPtr;
};

typedef struct QueueNode QueueNode;
typedef QueueNode *QueueNodePtr;

int isEmpty(QueueNodePtr headPtr);
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr * tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr,
	TreeNodePtr node);

int main(void)
{
	int i;
	int item;
	TreeNodePtr rootPtr = NULL;

	srand(time(NULL));
	printf("The values being inserted in the tree are:\n");


	for (i = 1; i <= 15; i++) {
		item = 1 + rand() % 20;
		printf(" %d", item);
		insertNode(&rootPtr, item);
	}


	printf("\n\nThe level-order traversal is:\n");
	levelOrderTraversal(rootPtr);
	printf("\n");

	return 0;
}

void levelOrderTraversal(TreeNodePtr ptr)
{
	QueueNodePtr head = NULL, tail=NULL;
	TreeNodePtr node = NULL;

	if (ptr != NULL)
	{
		enqueue(&head, &tail, ptr);
		while (!isEmpty(head))
		{
		    node = dequeue(&head, &tail);

			printf("%-5d", node->data);

			if (node->leftPtr != NULL)
				enqueue(&head, &tail, node->leftPtr);

			if (node->rightPtr != NULL)
				enqueue(&head, &tail, node->rightPtr);
	}}
}


void insertNode(TreeNodePtr * treePtr, int value)
{
	if (*treePtr == NULL) 
	{
		*treePtr = malloc(sizeof(TreeNode));

		if (*treePtr != NULL)
		{
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}else 
			printf("%d not inserted. No memory available.\n", value);
	}else
	{
		if (value < (*treePtr)->data) 
			insertNode(&((*treePtr)->leftPtr), value);
		else if (value >(*treePtr)->data) 
			insertNode(&((*treePtr)->rightPtr), value);
		else 
			printf("dup");
	}
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr node)
{
	QueueNodePtr newPtr;


	newPtr = malloc(sizeof(QueueNode));


	if (newPtr != NULL) {
		newPtr->data = node;
		newPtr->nextPtr = NULL;


		if (isEmpty(*headPtr)) {
			*headPtr = newPtr;
		}
		else {
			(*tailPtr)->nextPtr = newPtr;
		}

		*tailPtr = newPtr;
	}
	else {
		printf("Node not inserted\n");
	}

}


TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	TreeNodePtr node;
	QueueNodePtr tempPtr;


	node = (*headPtr)->data;
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;


	if (*headPtr == NULL) {
		*tailPtr = NULL;
	}

	free(tempPtr);

	return node;

}


int isEmpty(QueueNodePtr headPtr)
{
	return headPtr == NULL;

}


