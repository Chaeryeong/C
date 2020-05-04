#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	char f1[80], f2[80], buffer[100];

	FILE *fp1;
	FILE *fp2;

	printf("Enter the name of file to read: "); scanf("%s", f1);
	printf("Enter the name of file to write: "); scanf("%s", f2);

	if ((fp1 = fopen(f1, "rt")) == NULL || (fp2 = fopen(f2, "wt")) == NULL) {
		puts("File could not be opened\n");
		return -1;
	}
	else
	{
		fp2 = fopen(f2, "w");
		while (fgets(buffer, 100, fp1) != NULL)
			if (*buffer != '\n')
				fputs(buffer, fp2);
	}

	printf("Copy txt Complete!\n");
	fclose(fp1); fclose(fp2);
	return 0;
}