#include<stdio.h>
#include<string.h>

int main(){
    char name[100];
    scanf("%[^\n]%*c", name);
    // printf("%s", name);

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
                // printf("%c - caserd", ch);
                
            }else if(ch == '1'){
                    ans[ansindex++] = name[i];
                    // printf("%c", name[i]);
                         ch = name[i];
            }else{
                // printf("%c", ch);
                   ans[ansindex++] = ch;
             } }
    }
  
         
        for(int i = 0; i < ansindex; i++){
         if(ans[i] == '1'){
            printf("-"); 
         }
        printf("%c", ans[i]);
     }
     
    return 0;
}
              