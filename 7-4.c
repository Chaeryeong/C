#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[10][100];
	char buf[100];
	int i, j, k;
	int loof = 0;

	for (i = 0; i < 10; i++) {
		printf("Enter a string: "); 
		scanf("%s", str[i]);
	}

	for (loof = 0; loof < 9; loof++) {
		for (j = 0; j < 9 - loof; j++) {
			if (strcmp(str[j], str[j + 1]) > 0) {
				strcpy(buf, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], buf);
			}
		}
	}

	printf("\nThe strings in sorted order are:\n");

	for (k = 0; k < 10; k++) {
		printf("%s\n", str[k]);
	}

	return 0;
}