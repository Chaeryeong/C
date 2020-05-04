#include<stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);

typedef int(*FUNC)(int, int); 

int main(void) {
	int(*func[3])(int, int) = { add, sub, mul };
	char operator[3] = { '+', '-', '*' };
	size_t select;
	int n1, n2;
	int result;

	printf("0.Addition\n");
	printf("1.Subtraction\n");
	printf("2.Multiplication\n");
	printf("3.End\n");
	printf("Select the operation: ");
	scanf("%d", &select);
	if (select == 3) {
		printf("Exit\n");
		exit(0);
	}
	printf("Enter the two numbers: ");
	scanf("%d %d", &n1, &n2);
	result = (*func[select])(n1, n2);
	printf("\t%d %c %d = %d\n", n1, operator[select], n2, result);

}



int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}