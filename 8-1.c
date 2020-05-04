#include<stdio.h>

void bitCheck(int integer); 

int main()
{
	int input = 0;

	while (1) {
		printf("Enter an integer: ");
		scanf("%d", &input);
		bitCheck(input);
	}
}

void bitCheck(int integer) {
	int i = 0;
	int count = 0;

	for (i = 0; i < 32; i++) {
		if (integer & 0x00000001 != 0) count++;

		integer = integer >> 1;
	}

	if (count % 2 == 1) printf("The total number of 1s in the representation is odd\n\n");
	else printf("The total number of 1s in the representation is even\n\n");
}