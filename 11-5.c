#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
	struct treeNode *leftPtr;
	int data; 
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;

void insert_Node(TreeNodePtr * treePtr, int value)
{
	if (*treePtr == NULL)
	{
		*treePtr = malloc(sizeof(TreeNode));

		if (*treePtr != NULL)
		{
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else
			printf("%d not inserted. No memory available.\n", value);
	}
	else
	{
		if (value < (*treePtr)->data)
			insert_Node(&((*treePtr)->leftPtr), value);
		else if (value >(*treePtr)->data)
			insert_Node(&((*treePtr)->rightPtr), value);
		else
			printf("dup");

	}
}

void output_Tree(TreeNodePtr treePtr, unsigned level)
{
	int n = 1;

	if (treePtr != NULL)
	{
		output_Tree(treePtr->rightPtr, level + 1);

		while (n < level)
		{
			printf("    ");
			n++;
		}

		printf("%d\n", treePtr->data);

		output_Tree(treePtr->leftPtr, level + 1);
	}
}

int main(void)
{
	int idx;
	int it;

	TreeNodePtr rootPtr = NULL;

	srand(time(NULL));

	printf("The numbers being placed in the tree are:\n");

	for (idx = 0; idx <= 10; idx++)
	{
		it = rand() % 15;
		printf("%3d", it);
		insert_Node(&rootPtr, it);
	}

	printf("\n");

	output_Tree(rootPtr, 1);

}



