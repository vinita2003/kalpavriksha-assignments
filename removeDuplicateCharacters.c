#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 50

int main(){
    char input[50];
    fgets(input, 50, stdin);

    // input[strpn(input, "\n")] = '\0';
    int size = strlen(input);

    int ans[size];

    for(int i = 0; i < size; i++){
        ans[i] = 0;
    }

    for(int index = 0; index < size; index++){
        for(int index1 = 0; index1 <= index; index1++){
            if(input[index] == input[index1]){
                ans[index1]++;
                break;
                // ans[index] = 0;
            }
        }
    }

    for(int index = 0; index < size; index++){
        if(ans[index] != 0){
            printf("%c", input[index]);
        }
    }

    return 0;
}