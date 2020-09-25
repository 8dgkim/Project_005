#include <stdio.h>

#define CONTENT 1000

int main_interrogation(void)
{
	int age = 0;
	float weight, height;
	char name[CONTENT], crime[CONTENT];

	printf("You are currently interrogated by a police officer.\nPlease answer the questions carefully.\n");

	printf("What is your name?\n");
	scanf_s("%s", name, sizeof(name));

	printf("What is your age?\n");
	scanf_s("&d", age);

	printf("What is your weight?");
	scanf_s("%f", &weight);

	printf("What is your height?");
	scanf_s("%f", &height);

	printf("What crime did you commit?");
	scanf_s("%s", crime, sizeof(crime));

	printf("Your name: %s\nYour age : %d\nYour weight : %.2f\nYour height : %.2f\nYour crime : %s\n",name, age, weight, height, crime);

	return 0;
}