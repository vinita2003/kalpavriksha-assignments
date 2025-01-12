#include<stdio.h>
#include <string.h>
#include <limits.h>

int containsAllCharacters(char* s, char* p)
{
    int count[256] = { 0 };

   
    for (int i = 0; p[i] != '\0'; i++)
        count[(unsigned char)p[i]]++;

    
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[(unsigned char)s[i]] > 0)
            count[(unsigned char)s[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] > 0)
            return 0;
    }

    return 1;
}

void findSmallestSubstring(char *input1, char*input2, char*result){
    int size1 = strlen(input1);
    int size2 = strlen(input2);
    int minlen = INT_MAX;

    result[0] = '\0';

    for(int i = 0; i < size1; i++){
        for(int j = i; j <= size1; j++){
           char substr[100];
           strncpy(substr, input1+i, j-i+1);
           substr[j-i+1] = '\0';

           if(containsAllCharacters(substr, input2)){
            int currlen = strlen(substr);

            if(currlen < minlen){
            minlen = currlen;
            strcpy(result, substr);
           }
           }
           
        }
    }
}

int main(){
    char input1[100];
    fgets(input1, 100, stdin);
    char input2[100];
    fgets(input2, 100, stdin);

    char result[100];

    findSmallestSubstring(input1, input2, result);
    if (strlen(result) > 0) {
        printf("%s\n", result);
    } else {
        printf("-1\n");
    }
    return 0;
}