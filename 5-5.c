#include<stdio.h>
#define SIZE 100

char revstr[SIZE];

int testPalindrome(char str[], char revstr[]);
void reverseString(char str[]);

int main() {

	int result;
	int i, j;

	char str[SIZE];
	char str2[SIZE];

	printf("Enter a sentence :\n");
	gets(str);

	for (i = 0; i < str[i] != 0; i++)
		str2[i] = str[i];

	str2[i] = 0;

	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == ' ' || str[i] == '.')
		{
			for (j = i; str[j] != 0; j++)
				str[j] = str[j + 1];
			i--;
		}
	}

	reverseString(str);
	result = testPalindrome(str, revstr);

	if (result == 1) {
		printf("\"%s\" is a palindrome \n", str2);
	}
	else {
		printf("\"%s\" is not a paindrome \n", str2);
	}

	return 0;
}

int testPalindrome(char str[], char revstr[]) {

	static int i = 0;

	if (str[i] == 0) {
		return 1;
	}

	if (str[i] != revstr[i]) {
		return 0;
	}

	i++;

	return testPalindrome(str, revstr);
}
 
void reverseString(char str[]) {

	static int i = 0;

	if (str[0] == 0 || str[0] == '.') {
		return;
	}

	reverseString(str + 1);

	revstr[i++] = str[0];
}