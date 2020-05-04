#include <stdio.h>
#include <math.h>

int reverse(int a);

int main(void) {
	int input;
	printf("Ener a number between 1 and 9999: ");
	scanf_s("%d", &input);

	printf("The number with its digits reversed is: %d\n", reverse(input));

	return 0;
}

int reverse(int a) {
	int reverse = 0, rem;

	if (a == 0) return 0;
	while (a != 0)
	{
		rem = a % 10;
		reverse = reverse * 10 + rem;
		a /= 10;
	}
	return reverse;

}