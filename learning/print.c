#include <stdio.h>
#include <string.h>

int main()
{
	printf("1234567890");
	printf("\n");
	printf("__________");
	printf("\n");
	printf("%6d%-3d", 25, 7);
	printf("\n");
	printf("%8.2f", 123.456);
	printf("\n");
	printf("%-10s%4d", "Hello", 42);
	printf("\n");
	printf("%-9.4f", 1.234567);
	printf("\n");

	return 0;
}
