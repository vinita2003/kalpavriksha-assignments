#include<stdio.h>
#include<string.h>

int mystrlen(const char* str){
    int len = 0;
    int index = 0;

    while(str[index] != '\0'){
        len++;
        index++;
    }
    return len;
}
void mystrcpy(char *s, char *t)
{
  while (*s++ = *t++);
    
}

void removeAdjacentDuplicate(char *str){
    char stack[mystrlen(str) +1];

    int top = -1;

    for(int index = 0; str[index] != '\0'; index++){
       if(top >= 0 && (stack[top] == str[index])){
        top--;
       }else{
        stack[++top] = str[index];
       }
    }

    stack[top] = '\0';

    mystrcpy(str, stack);

}

int main(){

    char input[100];
    fgets(input, 100, stdin);

    // int size = strlen(input);
    
    removeAdjacentDuplicate(input);
    if(mystrlen(input) == 0){
        printf("  ");
    }

    printf("%s", input);
    
    return 0;
}