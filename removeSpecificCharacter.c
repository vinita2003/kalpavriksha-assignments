#include<stdio.h>

int mystrlen(const char* str){
    int len = 0;
    int index = 0;

    while(str[index] != '\0'){
        len++;
        index++;
    }
    return len;
}

int main(){
    char input[100];
    fgets(input, 100, stdin);

    char ch;
    scanf("%c", &ch);
    int size = mystrlen(input) - 1;
    char name[100];
    int index1 = 0;

    for(int index = 0; input[index] != '\0'; index++){
        if(input[index] != ch){
          name[index1++] = input[index];
        }
    }

    printf("%s\n", name);

    return 0;
}