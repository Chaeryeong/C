#include <stdio.h>
int main() {
	int base, exponent, input, result = 1, count;

	do {
		printf("Enter the base number: ");
		scanf("%d", &input);
	} while (input <= 0);

	base = input;

	do {
		printf("Enter the exponent number: ");
		scanf("%d", &input);
	} while (input < 0);

	exponent = input;

	for (count = 0; count < exponent; count++) {
		result *= base;
	}
	printf("%d^%d is %d\n", base, exponent, result);

	return 0;

}