#include <stdio.h>

int main(void)
{
	int smallest, largest, num1, num2, num3, temp;

	printf("Input 5 integers: ");
	scanf("%d%d%d%d%d", &smallest, &largest, &num1, &num2, &num3);

	if (smallest >= largest) {
		temp = largest;
		largest = smallest;
		smallest = temp;
	}
	if (num1 >= largest) {
		largest = num1;
	}
	if (num2 >= largest) {
		largest = num2;
	}
	if (num3 >= largest) {
		largest = num3;
	}
	printf("The largest value is %d\n", largest);
	if (num1 < smallest) {
			smallest = num1;
		}
	if (num2 < smallest) {
			smallest = num2;
		}

	if (num3 < smallest) {
			smallest = num3;
		}
		
	printf("The smallest value is %d\n", smallest);

	return 0;

	}

