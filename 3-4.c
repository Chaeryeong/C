#include <stdio.h>
int main() {
	int a, b, star = 9;
	for (a = 1; a < star; a += 2) {

		for (b = 1; b <= (star - a) / 2; b++)
			printf(" ");
		for (b = 1; b <= a; b++)
			printf("*");

		printf("\n");

	}

	for (a = star; a >= 1; a -= 2) {

		for (b = 1; b <= (star - a) / 2; b++)
			printf(" ");
		for (b = 1; b <= a; b++)
			printf("*");

		printf("\n");
	}
	return 0;
}