/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include<string.h>

int main()
{
    // printf("Hello World");
    
    char name[50];
    // scanf("%s^\n", name);
    fgets(name, 50, stdin);
    printf("%s", name);
    name[strcspn(name, "\n")] = '\0';
    
    int i = 0;
    int temp = 0;
    
    while(name[i] != '\0'){
        if(isdigit(name[i])){
            temp = temp*10 + (name[i] - '0');
        }else if(name[i] == '.'){
            if(name[i+1] == 0 || name[i+1] == '.' || name[i+1] == ',' ){
                printf("INVALID");
                return 0;
            }
            if(temp <= 0 || temp >= 256){
                printf("INVALID");
                return 0;
            }
        }
            else if(name[i] == ','){
            printf("INVALID");
                return 0;
    }
    i++;
    }
    
    printf("VALID");
    
    
    
    

    return 0;
}