#include<stdio.h>
#include<string.h>

int main() {
	FILE *fp;
	char text[10000], read[100], words[100], *ptr;
	int count = 0, wordcount = 0;

	printf("Enter the file name and word : ");
	scanf("%s%s", read, words);

	if ((fp = fopen(read, "r")) == NULL) {
		printf("File could not be opened\n");
		return -1; 
	}
	else {
		fgets(text, sizeof(text), fp);
		ptr = strtok(text, " ()-,&.");
		while (ptr != NULL) {
			count++;
			if (!strcmp(words, ptr)) {
				wordcount++;
			}
			ptr = strtok(NULL, " ()-,&.");
		}
		printf("The finding ratio : %d/%d\n", wordcount, count);
		fclose(fp);
	}
	return 0;
}