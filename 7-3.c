#include<stdio.h>
#include<string.h>

void lengthChar(char* ptr);
void printLength(int count_a, int a);

int count_1 = 0;
int count_2 = 0;
int count_3 = 0;
int count_4 = 0;
int count_5 = 0;
int count_6 = 0;
int count_7 = 0;
int count_8 = 0;
int count_9 = 0;
int count_10 = 0;

int main(void)
{
	char str[1000] = { 0 };
	int count = 0;
	int i = 0;
	char* ptr;

	printf("Enter three lines of text:\n");

	for (i = 0; i < 1000 && count != 3; i++)
	{
		str[i] = getchar();
		if (str[i] == '\n') {
			count++;
			str[i] = ' ';
		}
		else if (str[i] == '.') i--;
	}

	ptr = strtok(str, " ");

	while (ptr != NULL)
	{
		lengthChar(ptr);
		ptr = strtok(NULL, " ");
	}

	printLength(count_1, 1);
	printLength(count_2, 2);
	printLength(count_3, 3);
	printLength(count_4, 4);
	printLength(count_5, 5);
	printLength(count_6, 6);
	printLength(count_7, 7);
	printLength(count_8, 8);
	printLength(count_9, 9);
	printLength(count_10, 10);

	return 0;
}

void lengthChar(char* ptr)
{
	if (strlen(ptr) == 1) count_1++;
	else if (strlen(ptr) == 2) count_2++;
	else if (strlen(ptr) == 3) count_3++;
	else if (strlen(ptr) == 4) count_4++;
	else if (strlen(ptr) == 5) count_5++; 
	else if (strlen(ptr) == 6) count_6++;
	else if (strlen(ptr) == 7) count_7++;
	else if (strlen(ptr) == 8) count_8++;
	else if (strlen(ptr) == 9) count_9++;
	else if (strlen(ptr) == 10) count_10++;
}

void printLength(int count_a, int a)
{
	if (count_a != 0) {
		if (count_a == 1) printf("%d word of length %d\n", count_a, a);
		else if (count_a > 1) printf("%d words of length %d\n", count_a, a);
	}
}