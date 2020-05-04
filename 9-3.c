#include<stdio.h>

int main() {

	int mat_1[2][3], mat_2[2][3], mat_3[2][3];

	FILE *fp1;
	FILE *fp2; 
	FILE *fp3;

	if ((fp1 = fopen("input.txt", "r")) == NULL) {
		printf("File could not be opened\n");
		return -1;
	}
	else {
		printf("input1 matrix :\n");
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				fscanf(fp1, "%d", &mat_1[i][j]);
				printf("%-7d", mat_1[i][j]);
			}
			printf("\n");
		}
		fclose(fp1);
	}
	printf("\n");
	if ((fp2 = fopen("input2.txt", "r")) == NULL) {
		printf("File could not be opened\n");
		return -1;
	}
	else {
		printf("input2 matrix :\n");
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				fscanf(fp2, "%d", &mat_2[i][j]);
				printf("%-7d", mat_2[i][j]);
			}
			printf("\n");
		}
		fclose(fp2);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			mat_3[i][j] = mat_1[i][j] + mat_2[i][j];
		}
	}
	printf("\n");

	if ((fp3 = fopen("result.txt", "w")) == NULL) {
		printf("File could not be opened\n");
		return -1;
	}
	else {
		printf("result matrix :\n");

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				fprintf(fp3, "%d", mat_3[i][j]);
				printf("%-7d", mat_3[i][j]);
				if (j != 2) {
					fprintf(fp3, "/");
				}
			}
			fprintf(fp3, "\n");
			printf("\n");
		}
		fclose(fp3);
	}
	printf("\n");
	return 0;
}