#include<stdio.h>

int main(){

    int row;
    scanf("%d", &row);
    

    int column;
    scanf("%d",  &column);
    

    int array[row][column];

    for(int index = 0; index < row; index++){
        for(int index1 = 0; index1 < column; index1++){
            scanf("%d", &array[index][index1]);
        }
    }
   
    int target;
    scanf("%d", &target);


    int start = 0;
    int end = column-1;
    int flag = 0;

    while(start < row && end >= 0){
        if(target = array[start][end]){
            flag = 1;
            break;
        }else if(array[start][end] > target){
            start++;
        }else{
            end--;
        }
    }
    if(flag == 1){
        printf("true");
    }else{
       printf("false"); 
    }
    

    return 0;
}