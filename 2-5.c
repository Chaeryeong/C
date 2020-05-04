#include  <stdio.h>
int main(void) {
	printf("Enter the number: ");
	int input, count = 0, largest, smallest, sum;
	float average;
	scanf("%d", &input);
	while (input != -1) {
		if (count == 0){
		     count += 1;
			largest = input;
			sum = input;
			smallest = input;
			printf("Enter the number: ");
			scanf("%d", &input);
		}
		else {
			count += 1;
			sum += input;
			if (input > largest) { largest = input; }
			if (input < smallest) { smallest = input; }
			average = (float)sum / count;
			printf("Enter the number: ");
			scanf("%d", &input);
		}
	}
	printf("The number of user's input: %d\n", count);
	printf("The sum of input numbers: %d\n", sum);
	printf("The average of input numbers: %.2f\n", average);
	printf("The largest number is: %d\n", largest);
	printf("The smallest number is: %d\n", smallest);
	return 0;
}