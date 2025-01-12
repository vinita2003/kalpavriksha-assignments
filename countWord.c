#include<stdio.h>
#include<string.h>
#include<ctype.h>

void leading(char *s) {
  
    int i = 0, j = 0;
    while (s[i] == ' ') i++;
    while (s[j++] = s[i++]);
    
}

void traling(char *str)
{
  int end;
  end = strlen(str) - 1;
  while(end > 0 && isspace((str[end]))) end--;

   str[end+1] = '\0';

}

int main(){
    char input[50];
    fgets(input, 50, stdin);

    char temp[50];
    int inputIndex = 0;
    int tempIndex = 0;
    int count = 0;

    leading(input);
    traling(input);
    // printf("%s ", input);

    while(input[inputIndex] != '\0')
    {
         if(input[inputIndex] != ' '){
            temp[tempIndex] = input[inputIndex];
            // printf("%c", temp[tempIndex]);
            tempIndex++;
        }else{
            if(tempIndex > 0){
                count++;
                tempIndex = 0;
            }
        }
        inputIndex++;
    }
    
    if(tempIndex > 0){
                count++;
                tempIndex = 0;
            }
   

    printf("\n%d", count);
    return 0;
}