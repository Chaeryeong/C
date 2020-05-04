#include<stdio.h>

int reverseBits(int data); 
void printBin(int decimal);

int main()
{
	int input = 0;
	int i;

	printf("Enter an unsigned integer: ");
	scanf("%d", &input);

	printf("\nBefore bits are reversed:\n");
	printf("\t%d = ", input);
	printBin(input);

	printf("After bits are reversed:\n");
	printf("\t%d = ", reverseBits(input));
	printBin(reverseBits(input));

	return 0;
}

int reverseBits(int data) {
	int retdata = 0;
	int i = 0;
	for (i = 0; i < 16; i++) {
		if ((data&(1 << i)) == 0) {
			/*Skip*/
		}
		else retdata = retdata | (0x8000 >> i);
	}
	return retdata;
}

void printBin(int decimal) {
	int i;

	for (i = 16; i > 0; i--) {
		printf("%d", (decimal >> i - 1) & 1);
		if (i == 9) printf(" ");
	}

	printf("\n\n");
}