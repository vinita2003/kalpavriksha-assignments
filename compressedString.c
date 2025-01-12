#include<stdio.h>

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

    int size = mystrlen(input) - 1;
    printf("%d\n", size);

   int ans[100] = {0};
//   int ansIndex = 0;
    for(int index = 0; index < size; index++){
        for(int index1 = 0; index1 <= index; index1++){
            if(input[index1] == input[index]){
                
                    ans[index1]++;
                    break;
                
               
            }
        }
    }
    int count = 0;
    for(int index = 0; index < size;index++){
        if(ans[index] == 1){
           count++;
        }
    }

  if(size == count){
    printf("%s", input);
  }
  else{
     for(int index = 0; index < size; index++){
        if(ans[index] > 0){
            printf("%c", input[index]);
            printf("%d", ans[index]);
        }
    } 
  }
   return 0; 
}