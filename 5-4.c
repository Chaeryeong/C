#include<stdio.h>

void stringReverse(char strArray[]);

int main(void)
{
	char strArray[30] = "Print this string backward.";
	printf("%s\n", strArray);
	stringReverse(strArray);
	printf("\n");
} 

void stringReverse(char strArray[]) {
	if (strArray[0] == '\0') return;
	stringReverse(strArray + 1);
	printf("%c", strArray[0]);
} 