#include<stdio.h>

void func(int* a, int* b, int* c);

int main(void) {
	 
	int a = 0, b = 0, c = 0;

	printf("Enter three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("Before: a= %d, b= %d, c= %d\n", a, b, c);
	func(&a, &b, &c);
	printf("After: a= %d, b= %d, c= %d\n", a, b, c);

	return 0;
}

void func(int* a, int* b, int* c) {
	int temp = 0;
	*a = *a + 1;
	*b = *b * *c;
	temp = *b;
	*b = *c;
	*c = temp;

}