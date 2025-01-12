#include <stdio.h>
#include <string.h>
 
int main()
{
   int rows;
   scanf("%d", &rows);
   int columns;
   scanf("%d", &columns);
   char string[rows][columns][50];
   for(int index = 0; index < rows; index++){
       for(int index1 = 0; index1 < columns; index1++){
           scanf("%s", string[index][index1]);
       }
   }

 char str[rows*columns][50];
 int istr = 0;
 
 for(int index = 0; index < rows; index++){
     for(int index1 = 0; index1 < columns; index1++){
         strcpy(str[istr++], string[index][index1]);
     }
 }
 
 int ans[100] = {0};
 
 for(int index =0; index < rows*columns; index++){
     for(int index1 = 0; index1 <= index; index1++){
        if(strcmp(str[index1], str[index]) == 0){
            ans[index1]++;
            break;
        }
     }
 }
 
   for(int index = 0; index < rows*columns; index++){
       if(ans[index] > 1){
           printf("%s - %d\n", str[index], ans[index]);
           ans[index] = 0;
       }
   }

 
    return 0;
}
