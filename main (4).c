/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{ 
    char input[50];
  fgets(input, 50, stdin);
   input[strcspn(input, "\n")] = '\0';
    char required_char;
    scanf("%c", &required_char);
    
    int count = 0;
    
    char input2[50];
    int index2 = 0;
    int index1 =0;
    
     while(input[index1] != '\0'){
         if(input[index1] != ' '){
               input2[index2++] = input[index1];
               

            
         }
         index1++;
         }
         
     input2[index2] = '\0';
     int index3 = 0; 
     while(input2[index3] != '\0'){
         if(input2[0] == input2[index3]){
             count++;
         }
         index3++;
     }
    
    if(count > 0){
         printf("%s", input2);
    }else {
        input[0] = required_char;
        printf("%s", input2);
    }
    
   
    
    

    return 0;
}