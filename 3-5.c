#include<stdio.h>
int main() {
	int productnumber, productcount, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
	double price1 = 2.98, price2 = 4.50, price3 = 9.98, price4 = 4.49, price5 = 6.87;
	double total = 0;

	printf("Enter pairs of item numbers and quantities.\nEnter -1 for the item number to end input.\n");

	do {
		scanf("%d", &productnumber);
		if (productnumber == -1) {
			productcount = 0;
			total = (n1*price1) + (n2*price2) + (n3*price3) + (n4*price4) + (n5*price5);
			printf("The total retail value was: %.2lf\n", total);
			return 0;
		}
		else
	 {
			scanf("%d", &productcount);
			switch (productnumber) {
				case 1:
					n1 += productcount;
					break;

				case 2:
					n2 += productcount;
					break;

				case 3:
					n3 += productcount;
					break;

				case 4:
					n4 += productcount;
					break;

				case 5:
					n5 += productcount;
					break;

				default:
					printf("Invalid product code: %d\n\tQuantity: %d\n", productnumber, productcount);
					break;
			}

		}
	} while (productnumber != -1);
}