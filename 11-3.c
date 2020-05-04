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
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, const int key);

int main(void)
{
	int i;
	int item;
	int searchKey;
	TreeNodePtr rootPtr = NULL;
	TreeNodePtr searchResultPtr;

	srand(time(NULL));
	printf("The numbers being placed in the tree are:\n");


	for (i = 1; i <= 10; i++) {
		item = 1 + rand() % 20;
		printf("%3d", item);
		insertNode(&rootPtr, item);
	}

	printf("\n\nEnter an integer to search for: ");
	scanf_s("%d", &searchKey);

	searchResultPtr = binaryTreeSearch(rootPtr, searchKey);


	if (searchResultPtr == NULL) {
		printf("\n%d was not found in the tree.\n\n", searchKey);
	}
	else {
		printf("\n%d was found in the tree.\n\n",
			searchResultPtr->data);
	}

	return 0;
}


void insertNode(TreeNodePtr * treePtr, int value)
{
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		if (*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}else 
			printf("%d not inserted. No memory available.\n", value);
	}else {
		if (value < (*treePtr)->data) 
			insertNode(&((*treePtr)->leftPtr), value);
		else if (value >(*treePtr)->data) 
			insertNode(&((*treePtr)->rightPtr), value);
		else 
			printf("dup");
	}
}

TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, const int key)
{
	
	if (treePtr == NULL) 
		return NULL;

	if (key < treePtr->data) 
		return binaryTreeSearch(treePtr->leftPtr, key);
	else if (key > treePtr->data) 
		return binaryTreeSearch(treePtr->rightPtr, key);
	else 
		return treePtr;
}