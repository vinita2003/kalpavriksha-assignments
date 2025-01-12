/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

int main()
{
    // printf("Hello World");
    int row;
    scanf("%d", &row);
    
    int column;
    scanf("%d", &column);
    
    int **array = (int**)malloc(row*sizeof(int*));
    
    for(int i = 0; i < row; i++){
        array[i] = (int*)malloc(column*sizeof(int));
    }
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            scanf("%d", &array[i][j]);
        }
    }
    
    for(int i = 0; i < column*row -1; i++){
        
        for(int j = 0; j < column; j++){
            for(int k = 0; k < row; k++){
                if(i == (j+k)){
                    printf("%d ", array[j][k]);
                }
            }
        }
        
        printf("\n");
    }
    
    for(int i = 0; i < row; i++){
        free(array[i]);
    }
    free(array);
    return 0;
}