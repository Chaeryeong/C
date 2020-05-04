#include <stdio.h>

void hanoi(int num, int from, int to, int temp);

int main(void) {
	int num;
	printf("Enter the starting number of disks: ");
	scanf_s("%d", &num);

	hanoi(num, 1, 3, 2);

	return 0;
}

void hanoi(int num, int from, int to, int temp) {
	if (num > 0) {
		hanoi(num - 1, from, temp, to);
		printf("\n%d --> %d", from, to);
		hanoi(num - 1, temp, to, from);
	}
}