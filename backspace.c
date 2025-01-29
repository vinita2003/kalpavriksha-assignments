#include<stdio.h>
#include<string.h>

int main(){
    char name[50];
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';
    

    char name1[50];
    fgets(name1, 100, stdin);
    name1[strcspn(name1, "\n")] = '\0';
     printf("%s ", name);
      printf("%s ", name1);
    
    char name2[50];
    int j = -1;
    for(int i = 0; i < strlen(name); i++){
        if(name[i] == '#'){
            if(j == -1){
               continue;
            }else{
             j = j-1;
            }
           
        }else{
            name2[++j] = name[i];
        }
    }
    name2[++j] = '\0';


    char name3[50];
    int k = -1;
    for(int i = 0; i < strlen(name1); i++){
        if(name1[i] == '#'){
            if(k == -1){
                 continue;
            }else{
                 k = k-1;
            }
           
        }else{
            name3[++k] = name1[i];
        }
    }
    name3[++k] = '\0';
    int count = strcmp(name2, name3);
    printf("%s ", name2);
    printf("%s ", name3);
    if(count == 0){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}