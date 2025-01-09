#include <stdio.h>
#include <string.h>
 
int main()
{
   int m;
   scanf("%d", &m);
   int n;
   scanf("%d", &n);
   char string[m][n][50];
   for(int i = 0; i < m; i++){
       for(int j = 0; j < n; j++){
           scanf("%s", string[i][j]);
       }
   }

 char str[m*n][50];
 int istr = 0;
 
 for(int i = 0; i < m; i++){
     for(int j = 0; j < n; j++){
         strcpy(str[istr++], string[i][j]);
     }
 }
 
 int ans[100] = {0};
 
 for(int i =0; i < m*n; i++){
     for(int j = 0; j <= i; j++){
        if(strcmp(str[i], str[j]) == 0){
            ans[j]++;
            break;
        }
     }
 }
 
   for(int i = 0; i < m*n; i++){
       if(ans[i] > 1){
           printf("%s - %d\n", str[i], ans[i]);
           ans[i] = 0;
       }
   }

 
    return 0;
}