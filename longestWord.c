#include<stdio.h>
// #include<string.h>

void mystrcpy(char str1[30], char str2[30])
{
 int i;
 for(i=0;str1[i]!='\0';i++)
 {
  str2[i] = str1[i];
 }
 str2[i] = '\0';
}

int mystrlen(const char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}
int main(){
    char input[100] = {'\0'};
    fgets(input, 100, stdin);
    
    int inputIndex = 0;

    char string[100][100];
    int strIndex = 0;

    char temp[100];
    int tempIndex = 0;

    while(input[inputIndex] != '\0'){
        if(input[inputIndex] != ' '){
            temp[tempIndex++] = input[inputIndex];
        }else{
            if(tempIndex > 0){
                temp[tempIndex] = '\0';
                mystrcpy(temp,string[strIndex]);
                // printf("%s", string[strIndex]);
                strIndex++;
                tempIndex = 0;
            }
        }
        inputIndex++;
    }

    if(tempIndex > 0){
                mystrcpy(temp,string[strIndex++]);
                // strIndex = 0;

            }

            int max = 0;
            char ans[100];
            
            for(int index = 0; index < strIndex; index++){
                if(max < mystrlen(string[index])){
                    max = mystrlen(string[index]);
                    mystrcpy(string[index], ans);
                }
            }

            printf("%s", ans);
            return 0;

}