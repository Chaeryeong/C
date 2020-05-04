#include<stdio.h>

int main()
{
	char string[5][100];
	int j;

	for (j = 0; j < 5; j++)
	{
		printf("Enter a string: ");
		gets(string[j]);
	}

	printf("\nThe strings starting with 'b' and ending with 'ed' are:\n");

	for (j = 0; j < 5; j++)
	{
		if (string[j][0] == 'b' && strcmp(&string[j][strlen(string[j]) - 2], "ed") == 0)
			printf("%s\n", string[j]);
	}

	return 0;
}