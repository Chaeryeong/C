#include<stdio.h>
#include<string.h>

void searchChar(char* string, int upper, int lower);

int main(void)
{
	char str[1000];
	int count = 0;
	int i = 0;

	printf("Enter three lines of text:\n");

	for (i = 0; i < 1000 && count != 3; i++)
	{
		str[i] = getchar();
		if (str[i] == '\n') count++;
	}

	printf("\nThe total occurrences of each character:\n");

	searchChar(str, 'A', 'a');
	searchChar(str, 'B', 'b');
	searchChar(str, 'C', 'c');
	searchChar(str, 'D', 'd');
	searchChar(str, 'E', 'e');
	searchChar(str, 'F', 'f');
	searchChar(str, 'G', 'g');
	searchChar(str, 'H', 'h');
	searchChar(str, 'I', 'i');
	searchChar(str, 'J', 'j');
	searchChar(str, 'K', 'k');
	searchChar(str, 'L', 'l');
	searchChar(str, 'M', 'm');
	searchChar(str, 'N', 'n');
	searchChar(str, 'O', 'o');
	searchChar(str, 'P', 'p');
	searchChar(str, 'Q', 'q');
	searchChar(str, 'R', 'r');
	searchChar(str, 'S', 's');
	searchChar(str, 'T', 't');
	searchChar(str, 'U', 'u');
	searchChar(str, 'V', 'v');
	searchChar(str, 'W', 'w');
	searchChar(str, 'X', 'x');
	searchChar(str, 'Y', 'y');
	searchChar(str, 'Z', 'z');

	return 0;

}

void searchChar(char* string, int upper, int lower)
{
	int cnt = 0;
	char* pch = NULL;

	pch = strchr(string, upper);
	while (pch != NULL)
	{
		cnt++;
		pch = strchr(pch + 1, upper);
	}

	pch = strchr(string, lower);
	while (pch != NULL)
	{
		cnt++;
		pch = strchr(pch + 1, lower);
	}

	printf("%c: %d\n", lower, cnt);
}