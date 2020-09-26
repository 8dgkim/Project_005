#include <stdio.h>

typedef struct {
    char * name;
    int age;
    char * character;
    int level;
} CAT;


int collection[5] = {0,0,0,0,0};
CAT cats[5];


void initCats();
void printCat(int selected);
int checkCollection();




int main(void)
{
    int selected, collectAll;

    srandtime(time(NULL));

    initCats();
    while (1) {
        printf("Press any key to see which cat you'll have!\n");
        getchar();

        selected = rand() % 5;
        printCat(selected);
        collection[selected] = 1;

        collectAll = checkCollection();
        if (collectAll == 1) {
            break;
        }
    }
    return 0;
}


void initCats()
{
    cats[0].name = "깜냥이";
    cats[0].age = 5; 
    cats[0].character = "온순"; 
    cats[0].level = 1;

    cats[1].name = "귀요미";
    cats[1].age = 3; 
    cats[1].character = "날카롭"; 
    cats[1].level = 2;

    cats[2].name = "수줍이";
    cats[2].age = 7;
    cats[2].character = "늘 잠만 잠"; 
    cats[2].level = 3;

    cats[3].name = "까꿍이";
    cats[3].age = 2; 
    cats[3].character = "시끄러움"; 
    cats[3].level = 4;

    cats[4].name = "돼냥이";
    cats[4].age = 1; 
    cats[4].character = "배고픔"; 
    cats[4].level = 5;    
}


void printCat(int selected)
{
    int i;

    printf("\n\n === You now own this cat! ===\n\n");
    printf(" 이름 : %s\n", cats[selected].name);    
    printf(" 나이 : %d\n", cats[selected].age);
    printf(" 특징 : %s\n", cats[selected].character);
    printf(" 레벨 : ");

    for (i = 0; i < cats[selected].level; i++) {
        printf("%s", "9377");
    }
    printf("\n");
}

int checkCollection()
{
    int i;
    int collectAll = 1;

    printf("\n\n === List of cats you have === \n\n");
    for (i = 0; i < 5; i++) {
        if (collection[i] == 0) {
            printf("%10s", "(Empty Box)");
            collectAll = 0;
        } else {
            printf("%10s", cats[i].name);
        }
    }
    printf("\n=====================================\nn");

    if (collectAll) {
        printf("\n\n Congrats! You have collected all the cats.\n\n");
    }

    return collectAll;
}

