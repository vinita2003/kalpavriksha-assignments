#include<stdio.h>
#include<string.h>

int isPalindrome(char *str){
    int n = strlen(str);
    int flag = 1;

    for(int index = 0; index < n/2; index++){
        if(str[index] != str[n-1-index]){
            flag = 0;
            break;
        }
    }
    return flag;
}

void longestPalindrome(char * str, char *result){
       int size = strlen(str);
       int maxlen = 0;
    
    for(int index = 0; index < size; index++){
        for(int index1 = index; index1 < size; index1++){
            char st[50];
            strncpy(st, str+index, index1 - index +1);
            st[index1 - index+1]= '\0';

            if(isPalindrome(st)){
                int r = strlen(st);
                
                if(maxlen < r){
                    maxlen = r;
                    strcpy(result, st);
                }
            }
        }
    }

}

int main(){
    char input[50];
    scanf("%s", input);
   
    char result[50];

    longestPalindrome(input, result);
    printf("%s", result);
    return 0;
    
}