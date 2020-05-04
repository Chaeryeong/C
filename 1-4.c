#include <stdio.h>

int main(void)
{
    int num1 = 0;

	printf("number\tsquare\tcube\n");
	
	while (num1 <= 10) {
		printf("%d\t%d\t%d\n", num1, num1*num1, num1*num1*num1);
		num1 = num1 + 1;
	}

	return 0;

}