#include <stdio.h>

int main(void) {
	int integer1 = 0, integer2 = 0;
	int start = 0, end = 0, sum = 0;

	printf("Enter two integers : ");
	scanf("%d %d", &integer1, &integer2);
	if (integer1 < integer2) {
		start = integer1;
		end = integer2;
	}
	else {
		start = integer2;
		end = integer1;
	}
	while (start <= end) {
		sum = sum + start;
		start = start + 1;
	}
	printf("The sum of all integers between %d and %d is %d\n", integer1, integer2, sum);

	return 0;
}