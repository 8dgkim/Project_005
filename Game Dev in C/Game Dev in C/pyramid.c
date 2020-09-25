#include <stdio.h>

int main(void)
{
	int i, j, k;
	int floor;

	while (1) {
		printf("how many floors do you want?\n");
		scanf_s("%d", &floor);

		for (i = 0; i < floor; i++) {
			for (j = i; j < floor - 1; j++) {
				printf(" ");
			}
			for (k = 0; k < i * 2 + 1; k++) {
				printf("*");
			}
			printf("\n");
		}
	}


	//for (i = 0; i <= 9; i++) {
	//	for (j = i; j >= 0; j--) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	/*for (i = 10; i > 0; i -= 1) {
		for (j = 0; j < i; j += 1) {
			printf(" ");
		}
		printf("*");
	}*/

	/*for (i = 0; i < 5; i++) {
		for (j = i; j < 5 - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i; k++) {
			printf("*");
		}
		printf("\n");
	}*/




	return 0;
}