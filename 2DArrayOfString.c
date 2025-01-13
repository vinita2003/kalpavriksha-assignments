#include<stdio.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLS 10

int isVowel(char check_ch) {
    if (check_ch >= 'A' && check_ch <= 'Z') {
        check_ch = check_ch + 32;
    }
    return (check_ch == 'a' || check_ch == 'e' || check_ch == 'i' || check_ch == 'o' || check_ch == 'u');
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
    for(int index = 0; index < row; index++){
        for(int index1 = 0; index1 < columns; index1++){
            printf("Names at (%d , %d):" ,index,index1);
            scanf("%s", strings[index][index1]);
            if (isVowel(strings[index][index1][0])) {
                vowelCount++;
            }}}
     printf("The 2D array of names is:\n");
  for(int index = 0; index < row; index++){
        for(int index1 = 0; index1 < columns; index1++){
            
            printf("%s ", strings[index][index1]);
        }
        printf("\n");
    }

   printf("Number of names starting with a vowel: %d\n", vowelCount);
   char longestName[50];
   int max = 0;
   for(int index = 0; index < row; index++){
        for(int index1 = 0; index1 < columns; index1++){
            int r = strlen(strings[index][index1]);
            if(r > max){
                max = r;
                stringCopy(longestName ,strings[index][index1]);
            }}}
    printf("The longest name:");
    for (int index = 0; index < row; index++) {
        for ( int index1 = 0; index1 < columns; index1++) {
            if(strlen(longestName) == strlen(strings[index][index1])){
                printf("%s ", strings[index][index1]);
            }}}
   return 0;
}
