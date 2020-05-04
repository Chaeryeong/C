#include <stdio.h>

int main(void) {
	int integer1;
	int temp;
	int factorial = 1;

	printf("Enter a positive integer: ");
	scanf("%d", &integer1);
	
	temp = integer1;

	while (integer1 < 0) {
		printf("Enter a positive integer: ");
		scanf("%d", &integer1);
	}
	if (integer1 == 0) {
		factorial = 1;
	}
	
	if (integer1 > 0) {
		while (temp >= 1) {        
			factorial = factorial * temp;
			temp = temp - 1;
		}
		}

	printf("%d! is %d\n", integer1, factorial);

	return 0;
}