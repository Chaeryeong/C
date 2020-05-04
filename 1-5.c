#include <stdio.h>

int main(void) {
	int input, a, b, c, d, e;

	printf("Enter a five-digit number: ");
	scanf("%d", &input);

	a = input / 10000;
	input = input - a * 10000;
	b = input / 1000;
	input = input - b * 1000;
	c = input / 100;
	input = input - c * 100;
	d = input / 10;
	input = input - d * 10;
	e = input;

	printf("%d   %d   %d   %d   %d\n", e, d, c, b, a);
	printf("The sum of the digits : %d\n", a + b + c + d + e);

	return 0;
}