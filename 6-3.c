#include<stdio.h>

int strcat(char*s1, char* s2);

int main(void) { 
	char string1[80];
	char string2[80];

	printf("Enter two strings: ");
	scanf_s("%s%s", string1, 80, string2, 80);
	strcat(string1, string2);
	printf("%s\n", string1);
}

int strcat(char* s1, char* s2) {
	while (*s1 != NULL) {
		s1++;
	}
	do {
		*s1 = *s2;
		s1++;
		s2++;
	} while (*(s2 - 1) != NULL);
}