#include<stdio.h>

int myisdigit(char ch){
    int flag = 0;

    if(ch >= '0' && ch <= '9'){
        flag = 1;
    }
    return flag;
}

int main(){

    char name[100];
    fgets(name, 100, stdin);
    int index = 0;
    

    int num = 0;
    int is_negative = 0;

    while(name[index] != '\0'){
        if(!myisdigit(name[index]) && name[index] != '-'){
        
            break;
        }
        else if(name[index] == '-'){
            is_negative = 1;
        }
        else if(myisdigit(name[index])){
            num = num*10 + (name[index] - '0');
        }
        index++;

    }
    if(is_negative == 1){
        num = num*-1;
    }

    
        printf("%d", num);
    
    return 0;
}