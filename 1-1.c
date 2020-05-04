#include <stdio.h>

int main(void)
{
	int integer1;

	printf("Input an integer: ");
	scanf("%d", &integer1);

	if (integer1 % 2 == 0) {
		printf("%d is an even integer\n", integer1);
	}
	if (integer1 % 2 != 0) {
		printf("%d is an odd integer\n", integer1);
	}

	return 0;
}
