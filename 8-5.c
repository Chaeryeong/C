#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void select_menu();
void years();
void name();

struct student {
	char sn[20];
	char name[10];
	char es[10];
	char ks[10];
};

struct student std[1000];

int main() {

	printf("Score management\n\n");
	printf("Enter student number, english score, korean score respectively.\n");
	printf("When you enter student number 0, end input\n");

	for (int i = 0;; i++) {
		scanf("%s", std[i].sn);
		if (atoi(std[i].sn) == 0) {
			break;
		}
		scanf("%s%s%s", std[i].name, std[i].es, std[i].ks);
	}

	select_menu();

	return 0;
}

void select_menu() {

	int n_1;

	printf("Choose a search ways\n");
	printf("1. Student admission year\n");
	printf("2. Student name\n");
	printf("9. Exit\n");
	scanf("%d", &n_1);

	if (n_1 == 1) {
		years();
	}
	else if (n_1 == 2) {
		name();
	}
	else if (n_1 == 9) {
		return 0;
	}
	else
		select_menu();
}

void years() {

	int year = 0;
	int temp;

	printf("Enter the admission year.\n");
	scanf("%d", &year);

	for (int i = 0; i < 1000; i++) {
		temp = atoi(std[i].sn) / 1000000;
		if (temp == year) {
			printf("%s %s %s %s\n", std[i].sn, std[i].name, std[i].es, std[i].ks);
			printf("\n");
		}
	}

	select_menu();
}

void name() {

	char name[20];

	printf("Enter the student name\n");
	scanf("%s", name);

	for (int i = 0; i < 1000; i++) {
		if (!strcmp(name, std[i].name)) {
			printf("\n\n");
			printf("%s %s %s %s\n", std[i].sn, std[i].name, std[i].es, std[i].ks);
			printf("\n");
		}
	}

	select_menu();
}