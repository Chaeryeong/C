#include<stdio.h>

int main(void) {
	int number;
	int divider = 10000;
	int count = 0;

	printf("Enter a 5-digit number: ");
	scanf("%d", &number);

	int numcopy = number;
	while (divider >= 1) {
		if (numcopy / divider == 7) {
			count += 1;
		}
		numcopy = number % divider;
		divider /= 10;
	}
	printf("The number %d has %d seven(s) in it\n", number, count);
	
	return 0;
}