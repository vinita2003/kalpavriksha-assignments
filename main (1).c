/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    // printf("Hello World");
    
    int row;
    int column;
    
    scanf("%d", &row);
    scanf("%d", &column);
    
    int array[row][column];
    
    
    for(int i = 0; i < row; i++){
        for(int j =0; j < column; j++){
            scanf("%d", &array[i][j]);
        }
    }
    
    int transpose[row][column];
    
    for(int i = 0; i < row; i++){
        for(int j =0; j < column; j++){
            // scanf("%d", &array[i][j]);
            
            transpose[i][j] = array[j][i];
        }
    }
    
    for(int i = 0; i < row; i++){
        for(int j =0; j < column; j++){
            // scanf("%d", &array[i][j]);
            
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    

    return 0;
}