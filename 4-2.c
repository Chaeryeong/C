#include<stdio.h>
#include<math.h>

void isPerfect(int a);

int main(void) {
	int loop = 0;

	printf("For the integers from 1 to 1000:\n");
	for (loop = 1; loop <= 1000; loop++) {
		isPerfect(loop);
	}

	return 0;
}

void isPerfect(int a) { 
	int j, sum = 0;

	for (j = 1; j < a; j++)
		if (a%j == 0) sum += j;
	if (sum == a) printf("%d is perfect\n", a);

}