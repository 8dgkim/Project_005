#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

#define MAX 100000



int main(void)
{
    char line[MAX];
    char contents[MAX];
    char password[20];
    char c;
    int i = 0;

    printf("Welcome to the Secret Diary.\n");
    printf("Enter the password : ");

    while (1) {
        c = getch();
        if (c == 13) {
            password[i] = '\0';
            break;
        } else {
            printf("*");
            password[i] = c;
        }
        i++;
    }


    printf("\n\n === Security Check ===\n\n");
    if (strcmp(password, "beobwin") == 0) {

        printf(" === Password Confirmed === \n\n");
        char * fileName = "C:\\Users\\Owner\\OneDrive - swarthmore.edu\\김동규\\Computer\\Git\\cl-file-practice\\secretdiary.txt";
        FILE * file = fopen(fileName, "a");

        if (file == NULL) {
            printf("Failed to load file\n");
            return 1;
        }

        while (fgets(line, MAX, file) != NULL) {
            printf("%s", line);
        }

        printf("\n\n Continue writing! Type EXIT to exit.\n\n");

        while (1) {
            scanf("%[^\n]", contents);
            getchar();

            if (strcmp(contents, "EXIT") == 0) {
                printf("Terminating the sessions.\n\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file);
        }
        fclose(file);
    }
    else {
        printf(" === Incorrect password ===\n\n");
    }


    return 0;
}


