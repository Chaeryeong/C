#include<stdio.h>
#include<time.h>



int main(void)
{
	int arr[10];
	int i = 0;
	int temp; 

	srand((unsigned int)time(NULL));
	for (i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");

	for (i = 9; i >= 0; i--) {
		printf("%d ", *(arr + i));
	}
}