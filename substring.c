#include<stdio.h>
#include <string.h>

int main(){

    char string[50];
    fgets(string, 50, stdin);
    char substring[50];
    fgets(substring, 50, stdin);

    int stringIndex = 0, substringIndex = 0;

    int strIndex = -1;

    while(stringIndex < strlen(string) && substringIndex < strlen(substring)){
        if(string[stringIndex] == substring[substringIndex]){
            if(strIndex == -1){
                strIndex = stringIndex;
            }
            substringIndex++;
        }
        stringIndex++;
    }

    
        printf("%d", strIndex);
    
    return 0;
}