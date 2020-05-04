#include<stdio.h>
int main() {
	int acount = 0, bcount = 0, ccount = 0, dcount = 0, fcount = 0, count = 0;
	char input;
	double average = 0;
	printf("Enter the letter grades.\nEnter the EOF character to end input.\n");
	while ((input = getchar()) != EOF) {
		switch (input) {
		case 'A':
		case 'a':
			acount++;
			count++;
			break;
		case 'B':
		case 'b':
			bcount++;
			count++;
			break;
		case 'C':
		case 'c':
		    ccount++;
			count++;
			break;
		case 'D':
		case 'd':
			dcount++;
			count++;
			break;
		case 'F':
		case 'f':
			fcount++;
			count++;
			break;

		case ' ':
		case '\n':
		case '\t':
			break;

		default:
			printf("Incorrect Input DATA\n");
			break;
		}
	}
	average = (acount * 4 + bcount * 3 + ccount * 2 + dcount * 1) / count;
	printf("\nThe totals for each letter grade are:\nA: %d\nB: %d\nC: %d\nD: %d\nF: %d\n", acount, bcount, ccount, dcount, fcount);
	printf(average >= 3.5 ? "Average grade is A\n" : average >= 2.5 ? "Average grade is B\n" : average >= 1.5 ? "Average grade is C\n" : average >= 0.5 ? "Average grade is D\n" : "Average grade is F\n");

	return 0;
}