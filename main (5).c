#include<stdio.h>
#include<string.h>
int main(){
    char name[100];
    scanf("%[^\n]%*c", name);
if(strlen(name) == 0){
    return 0;
}
    char ans[100];
    int ansindex = 0;
    char ch;
    for(int i = 0; i < strlen(name); i++){
        if(i == 0){
            ans[ansindex++] = name[i];
            ch = name[i];
            }else{
           if(ch == name[i] || name[i-1] == name[i]){
                ans[ansindex] = '1';
                ch = ans[ansindex++];
                }else if(ch == '1'){
                    ans[ansindex++] = name[i];
                         ch = name[i];
            }else{
                   ans[ansindex++] = ch;
             } }
    }
  for(int index = 0; index < ansindex; index++){
         if(ans[index] == '1'){
            printf("-"); 
         }
        printf("%c", ans[index]);
     }
     return 0;
}
              
