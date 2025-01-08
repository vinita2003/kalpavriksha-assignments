#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLS 10

int isVowel(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
    }
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    int rows, cols, i, j;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];
    int vowelCount = 0;
    char longestName[MAX_NAME_LENGTH] = "";
    int longestLength = 0;

    printf("Enter number of rows :");
    scanf("%d", &rows);
    while (rows < 1 || rows > MAX_ROWS) {
        printf("Invalid input. Enter number of rows (1-10): ");
        scanf("%d", &rows);
    }

    printf("Enter number of columns : ");
    scanf("%d", &cols);
    while (cols < 1 || cols > MAX_COLS) {
        printf("Invalid input. Enter number of columns (1-10): ");
        scanf("%d", &cols);
    }

    printf("Enter the names:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
            if (isVowel(names[i][j][0])) {
                vowelCount++;
            }
            int currentLength = stringLength(names[i][j]);
            if (currentLength > longestLength) {
                longestLength = currentLength;
                stringCopy(longestName, names[i][j]);
            }
        }
    }

    printf("\nThe 2D array of names is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name:");
     for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if(strlen(longestName) == strlen(names[i][j])){
                printf("%s ", names[i][j]);
            }
            
        }
        
    }


    return 0;
}
