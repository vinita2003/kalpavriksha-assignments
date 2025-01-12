#include<stdio.h>

int main(){

    int row;
    scanf("%d", &row);
    
    int column;
    scanf("%d", &column);
    int array[row][column];

    for(int index = 0; index < row; index++){
        for(int index1 = 0; index1 < column; index1++){
            scanf("%d", &array[index][index1]);
        }
    }
    printf("\n");

    int temp[row][column];


 for(int index = 0; index < row; index++){
        for(int index1 = 0; index1 < column; index1++){
            // scanf("%d", &array[row][column]);
            temp[index][index1] = array[index][index1];
            //  printf("%d ", array[index][index1]);
        }
    }



     for(int index = 0; index < row; index++){
        for(int index1 = 0; index1 < column; index1++){
            if(array[index][index1] == 0){
               for(int index2 = 0; index2 < row; index2++){
                temp[index2][index1] = 0;
               }

               for(int index3 = 0; index3 < column; index3++){
                temp[index][index3] = 0;
               }
            }
        }
    }



    for(int index = 0; index < row; index++){
        for(int index1 = 0; index1 < column; index1++){
            
            array[index][index1] = temp[index][index1];
            printf("%d ", array[index][index1]);
        }
        printf("\n");
    }

    return 0;

    
}