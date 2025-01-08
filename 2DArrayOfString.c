#include<stdio.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLS 10

int isVowel(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
    }
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void stringCopy(char dest[], char src[]){
    int i = 0;
    while(src[i]!= '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main(){
    int row, columns;

    printf("Enter number of rows:");
    scanf("%d", &row);
    while (row < 1 || row > MAX_ROWS) {
        printf("Invalid input. Enter number of rows (1-10): ");
        scanf("%d", &row);
    }

    printf("Enter number of columns:");
    scanf("%d", &columns);
    while (columns < 1 || columns > MAX_COLS) {
        printf("Invalid input. Enter number of columns (1-10): ");
        scanf("%d", &columns);
    }

    printf("Enter the names:\n");

    char strings[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];

int vowelCount = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < columns; j++){
            printf("Names at (%d , %d):" ,i,j);
            scanf("%s", strings[i][j]);
            if (isVowel(strings[i][j][0])) {
                vowelCount++;
            }
            
        }
    }
     printf("The 2D array of names is:\n");
  for(int i = 0; i < row; i++){
        for(int j = 0; j < columns; j++){
            
            printf("%s ", strings[i][j]);
        }
        printf("\n");
    }

   

   printf("Number of names starting with a vowel: %d\n", vowelCount);

   char longestName[50];
   int max = 0;
   for(int i = 0; i < row; i++){
        for(int j = 0; j < columns; j++){
            int r = strlen(strings[i][j]);
            if(r > max){
                max = r;
                stringCopy(longestName ,strings[i][j]);
            }
        }
        
    }
    printf("The longest name:");
    
     for (int i = 0; i < row; i++) {
        for ( int j = 0; j < columns; j++) {
            if(strlen(longestName) == strlen(strings[i][j])){
                printf("%s ", strings[i][j]);
            }
            
        }
        
    }

   return 0;


}
