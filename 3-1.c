#include <stdio.h>
int main() {
	int input, largest, count = 0;

	do {
		printf("Enter the number: ");
		scanf("%d", &input);
		if (count == 0) {
			largest = input;
			count++;
		}
		else
		{
			if (largest < input) { largest = input; }
			count++;
		}
	} while (count < 5);

		printf("Largest is %d\n", largest);

		return 0;

	}
