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

  void mystrcat(char *dest, char *src)
{
 while(*dest != '\0'){
     dest++;
 }
 
 while(*src != '\0'){
     *dest = *src;
     dest++;
     src++;
 }
 *dest = '\0';

}
  int strsubstring(char *string, char *substring){
    int stringIndex = 0, substringIndex = 0;

    // int strIndex = -1;

    while(stringIndex < mystrlen(string) && substringIndex < mystrlen(substring)){
        if(string[stringIndex] == substring[substringIndex]){
            
            substringIndex++;
        }
        stringIndex++;
    }

    int count = -1;
    if(substringIndex == mystrlen(substring)){
        count = 1;
    }
    return count;
  }




int main(){

    char str1[100] = {'\0'};
    fgets(str1, 100, stdin);


    char str2[100] = {'\0'};
    fgets(str2, 100, stdin);

  

    if(mystrlen(str1) != mystrlen(str2)){  
        printf("Second string is not a rotation of first string");  
    }  
    else{  
     
        strcat(str1, str1);  
          
  
        if(strsubstring(str1, str2) != -1)  
            printf("Second string is a rotation of first string");  
        else  
            printf("Second string is not a rotation of first string");  
    }  
   
    return 0;  

}