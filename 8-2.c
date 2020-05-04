#include<stdio.h>

void printBin(int decimal);
int power2(int number, int pow);

int main() 
{
	int number = 0;
	int pow = 0;
	int result = 0;

	printf("Enter two integers: ");
	scanf("%d %d", &number, &pow);

	printf("number:\n");
	printf("\t%2d = ", number);
	printBin(number);

	printf("pow:\n");
	printf("\t%2d = ", pow);
	printBin(pow);

	result = power2(number, pow);

	printf("%d * 2^%d = %d\n", number, pow, result);
	printf("\t%2d = ", result);
	printBin(result);
}

void printBin(int decimal) {
	int i;

	for (i = 16; i > 0; i--) {
		printf("%d", (decimal >> i - 1) & 1);
		if (i == 9) printf(" ");
	}

	printf("\n\n");
}

int power2(int number, int pow) {
	return number * (2 << pow - 1);
}