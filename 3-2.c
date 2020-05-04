#include <stdio.h>
int main() {
	printf("Decimal\t\tBinary\n");
	int a;
	for (a = 0; a <= 15; a++) {
		printf("%d\t\t", a);
		printf(a / 8 == 1 ? "1" : "0");
		printf(a % 8 / 4 == 1 ? "1" : "0");
		printf(a % 8 % 4 / 2 == 1 ? "1" : "0");
		printf(a % 8 % 4 % 2 / 1 == 1 ? "1\n" : "0\n");
	}
	return 0;
}