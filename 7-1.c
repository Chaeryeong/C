#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int val = 0;
	char str[20];
	int total = 0;
	int i;

	for (i = 0; i < 4; i++) 
	{
		printf("Enter an integer string: ");
		scanf("%s", str);
		val = atoi(str);
		total += val;
	}

	printf("\nThe total of the value is %d\n", total);

	return 0;
}