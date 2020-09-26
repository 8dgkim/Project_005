#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_updown(void)
{
	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("Number : %d\n", num);
	int answer = 0;
	int chance = 5;

	while (chance > 0) {
		printf("Chances left : %d\n", chance--);
			printf("Guess the number (1~100) : ");
		scanf_s("%d", &answer);

		if (answer > num) {
			printf("DOWN\n\n");
		}
		else if (answer < num) {
			printf("UP\n\n");
		}
		else if (answer == num) {
			printf("Correct!\n\n");
			break;
		}
		else {
			printf("Unidentified error occurred\n");
		}


	}

}