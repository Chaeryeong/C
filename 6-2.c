#include<stdio.h>

int strcmp(const char*s1, const char* s2);

int main(void) {
	char string1[80];
	char string2[80]; 

	printf("Enter two strings: ");
	scanf_s("%s%s", string1, 80, string2, 80);
	printf("%s and %s are %s.\n", string1, string2, strcmp(string1, string2) ? "equal" : "not equal");
}

int strcmp(const char* s1, const char* s2) {
	do {
		if (*s1 == *s2) {
			s1++;
			s2++;
		}

		else return 0;
	} while (*s1 != NULL || *s2 != NULL);

	return 1;

}