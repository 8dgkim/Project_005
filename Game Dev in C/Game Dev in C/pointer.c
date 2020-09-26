#include <stdio.h>

void swap(int *a, int *b);

void main_pointer()
{
	int a = 10;
	int b = 20;

	printf("Before Swap function >> a : %d, b : %d\n", a, b);
	swap(&a, &b);
	printf("After Swap function >> a : %d, b : %d\n", a, b);
	
	return 0;
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	printf("Within Swap function >> a : %d, b : %d\n", *a, *b);
}
