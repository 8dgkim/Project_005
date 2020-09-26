#include <stdio.h>
#include <time.h>

int main_bald(void)
{
    int answer;
    int treatment = rand() % 4;
    int cntShowBottle = 0;
    int prevCntShowBottle = 0;
    int i, j;
    int bottle[4] = {0,0,0,0};
    int randBottle;
    int isincluded = 0;
    
    srand(time(NULL));
    printf("\n\n === Bald Game === \n\n");

    for (i = 1; i <= 3; i++) {
        do {
            cntShowBottle = rand() % 2 + 2;
        } while (cntShowBottle == prevCntShowBottle);

        printf(" > Attempt #%d : ", i);

        for (j = 0; j < cntShowBottle; j++) {
            randBottle = rand() % 4;

            if (bottle[randBottle] == 0) {
                bottle[randBottle] = 1;

                if (randBottle == treatment) {
                    isincluded = 1;
                }
            } else {
                j--;
            }
        }

        for (int k = 0; k < 4; k++) {
            if (bottle[k] == 1)
                printf("%d ", k + 1);
        }
        printf(" Putting the treatment on the head \n\n");

        if (isincluded == 1) {
            printf("   >> Success! Hair grown!\n");
        } else {
            printf("   >> Fail! Hair not grown!\n");
        }

        printf("\n ... Press any key to continue ... \n");
        scanf_s("%c", getchar());
    }

    printf("\n\nWhat is the treatment? \n");
    scanf_s("%d", &answer);

    if (answer == treatment + 1) {
        printf("\n >> Correct!\n");
    } else {
        printf("\n >> Wrong! The answer is %d.\n", treatment + 1);
    }
    return 0;
}