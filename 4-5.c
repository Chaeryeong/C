#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();

int main(void) {
	int i = 0;
	int j = 0;
	int total_h = 0;
	int total_t = 0; 

	srand(time(NULL));

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
		{
			if (flip() == 1) {
				printf("Heads ");
				total_h++;
			}
			else {
				printf("Tails ");
				total_t++;
			}
		}

		printf("\n");
	}

	printf("\nThe total number of Heads was %d\n", total_h);
	printf("The total number of Tails was %d\n", total_t);

	return 0;
}

int flip() {
	return rand() % 2;
}