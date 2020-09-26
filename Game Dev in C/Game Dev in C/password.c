#include <stdio.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main_password(void)
{
	int count = 0;
	int num1, num2;
	srand(time(NULL));
	int answer = -1;

	for (int i = 1; i < 5; i++) {
		num1 = getRandomNumber(i);
		num2 = getRandomNumber(i);
		showQuestion(i, num1, num2);

		scanf_s("%d", &answer);
		if (answer == -1) {
			printf("Ending the program\n");
			exit(0);
		}
		else if (answer == num1 + num2) {
			success();
			count++;
		}
		else
		{
			fail();
		}
	}
	return 0;
}

int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n##### Password (Level %d) #####\n\n\n", level);
	printf("\n\t%d x %d = ?\n\n", num1, num2);
	printf("####################\n");
	printf("\nType the password (close : -1) >> ");
}

void success()
{
	printf("\n >> Good!\n");
}

void fail()
{
	printf("\n >> Fail!\n");
}


