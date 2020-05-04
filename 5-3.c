#include<stdio.h>

int main(void)
{
	int i, j;
	int matrixA[5][6], matrixB[5][6], matrixR[5][6];

	srand((unsigned int)time(NULL));
	
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++) {
			matrixA[i][j] = rand() % 100 + 1;
			matrixB[i][j] = rand() % 100 + 1;
			matrixR[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}

	printf("matrix1:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++)
			printf("%3d  ", matrixA[i][j]);
		printf("\n");
	}

	printf("\nmatrix2:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++)
			printf("%3d  ", matrixB[i][j]);
		printf("\n");
	}

	printf("\nresult:\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6; j++)
			printf("%3d  ", matrixR[i][j]);
		printf("\n");
	}
}