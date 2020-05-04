
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int arResult[20];
	int i, j;
	int bExist;

	srand((unsigned int)time(NULL));

	printf("Nonrepetitive array values are:\n");

	for (i = 0; i < 20; i++)
	{
		do
		{
			arResult[i] = rand() % 20 + 1;
			bExist = 0;
			for (j = 0; j < i; j++)
			{
				if (arResult[j] == arResult[i])
				{
					bExist = 1;
					break;
				}
			}

		} while (bExist == 1);
	}

	for (i = 0; i < 20; i++)
		printf("Array[ %d ] = %d\n", i, arResult[i]);
}