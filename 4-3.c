
#include <stdio.h>
#include <math.h>

int ulcase(char a);

int main(void) {
	char input;
	while (1) {
		printf("Enter the character: ");

		input = getch();
		//scanf("%c", &input);
		printf("%c\n", input);

		printf("%c: %s\n", input, ulcase(input) == 1 ? "uppercase" : "lowercase");
	}
	return 0;
}

int ulcase(char a) {
	if ('A' <= a && a <= 'Z') return 1;

	return 0;
}