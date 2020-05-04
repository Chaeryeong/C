#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b);

int main(void)
{
	double input_1 = 0.0;
	double input_2 = 0.0;
	int count = 0;

	while (count < 3) 
	{
		printf("Enter the sides of the triangle: ");
		scanf_s("%lf %lf", &input_1, &input_2);

		printf("Hypotenuse: %.lf\n\n", hypotenuse(input_1, input_2));
		printf("\n");
		count++;
	}
	return 0;
}

double hypotenuse(double a, double b)
{
	double c = 0.0;

	c = sqrt(pow(a, 2) + pow(b, 2));

	return c;
}