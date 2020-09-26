#include <stdio.h>
#include <time.h>

int arrayAnimal[4][5];
int checkAnimal[4][5];
char * strAnimal[10];


void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();



int main_m_array(void)
{
	int failCount = 0;

	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	while (1) {
		int select1 = 0;
		int select2 = 0;
		int firstSelect_x, firstSelect_y;
		int secondSelect_x, secondSelect_y;


		printAnimals();
		printQuestion();
		printf("Select two cards to face up : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)
			continue;

		firstSelect_x = conv_pos_x(select1);
		firstSelect_y = conv_pos_y(select1);

		secondSelect_x = conv_pos_x(select2);
		secondSelect_y = conv_pos_y(select2);

		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0) && (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])) {
			printf("\n\nBingo! %s found\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;

		} else {
			printf("\n\n Nope! (Either wrong or already seen)\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;	
		}

		if (foundAllAnimals() == 1) {				
			printf("\n\n Congrats!! Found all animals. \n");
			printf("Total count of failed attempts : %d", failCount);
			break;
		}
	}

	return 0;
}

void initAnimalArray()
{
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "Monkey";
	strAnimal[1] = "Hippo";
	strAnimal[2] = "Dog";
	strAnimal[3] = "Cat";
	strAnimal[4] = "Pig";

	strAnimal[5] = "Elephant";
	strAnimal[6] = "Giraffe";
	strAnimal[7] = "Camel";
	strAnimal[8] = "Ostrich";
	strAnimal[9] = "Tiger";
}

void shuffleAnimal()
{
	int i, j;
	int pos, x, y;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 2; j++) {
			pos = getEmptyPosition();
			x = conv_pos_x(pos);
			y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;

		}
	}
}

int getEmptyPosition()
{
	int randPos, x, y;

	while (1) {
		randPos = rand() % 20;
		x = conv_pos_x(randPos);
		y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	return x / 5; 
}
	
int conv_pos_y(int y)
{
	return y % 5;
}

void printAnimals()
{
	int i, j;

	for (i=0; i<4; i++) {
		for (j= 0; j <5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n==========================================\n\n");
}


void printQuestion()
{
	int seq = 0;
	int i, j;

	printf("\n\n(Problem)\n");

	for (i=0; i<4;i++) {			
		for (j =0; j<5; j++) {
			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
				
			} else {
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
	
}

int foundAllAnimals()
{
	int i, j;

	for (i = 0; i <4; i++) {
		for (j=0; j<5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;

}
