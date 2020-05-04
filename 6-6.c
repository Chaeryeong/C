#include <stdio.h>
#include <string.h>

int hard(char *string);
void spellcheck(char *string);


int main(void)
{
	char string[] = "I love programiing, but i am not goad at programiing. I will practice hard to do programiing well."
		" I will be attending class hard to be goad at programiing. I will study hard and get goad score in midterm exem.";

	printf("Before spell check: \n%s \n\n", string);
	
	spellcheck(string);

	printf("After spell check; \n%s \n\n", string);
	printf("How many word hard in the string : %d \n", hard(string));

	return 0;
}

void spellcheck(char *string)
{
	int i;
	char a[] = "programming";
	char b[] = "good";
	char c[] = "exam";
	char *ptr = string;

	while ((ptr = strstr(string, "programiing")) != '\0')
		for (i = 0; a[i] != 0; i++)
			ptr[i] = a[i];

	while ((ptr = strstr(string, "goad")) != '\0')
		for (i = 0; b[i] != 0; i++)
			ptr[i] = b[i];

	while ((ptr = strstr(string, "exem")) != '\0')
		for (i = 0; c[i] != 0; i++)
			ptr[i] = c[i];
}

int hard(char *string)
{
	int a = 0;

	while ((string = strstr(string, "hard")) != '\0')
	{
		string += 4;
		++a;
	}

	return a;
}