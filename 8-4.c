#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
	char name[80];
	int stdnum;
};

int main()
{
	struct student s[5];

	int i, j;
	char input[100] = { 0 };
	int loof = 0;
	int temp = 0;
	char tempchar[100] = { 0 };

	for (i = 0; i < 5; i++) {
		printf("<%d>Enter student name / student number: ", i + 1);
		gets(input);
		strcpy(s[i].name, strtok(input, "/"));
		s[i].stdnum = atoi(strtok(NULL, "/"));
	}

	for (loof = 0; loof < 4; loof++) {
		for (j = 0; j < 4 - loof; j++) { 
			if (s[j].stdnum > s[j + 1].stdnum) {
				temp = s[j].stdnum;
				s[j].stdnum = s[j + 1].stdnum;
				s[j + 1].stdnum = temp;

				strcpy(tempchar, s[j].name);
				strcpy(s[j].name, s[j + 1].name);
				strcpy(s[j + 1].name, tempchar);
			}
		}
	}

	printf("\nID\t\tName\n");
	for (i = 0; i < 5; i++) printf("%d\t%s\n", s[i].stdnum, s[i].name);

	return 0;
}