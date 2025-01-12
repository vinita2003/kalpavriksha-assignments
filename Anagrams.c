#include <stdio.h>
#include <string.h>

void sorting(char *s) {
    int n = 0;
    while (s[n] != '\0') n++; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
int main(){
    char input1[50];
    char input2[50];
     
     fgets(input1, 50, stdin);
     fgets(input2, 50, stdin);

     sorting(input1);
     sorting(input2);

     if(strcmp(input1, input2) == 0){
        printf("True");
     }else{
          printf("False");
     }
     
     return 0;
}