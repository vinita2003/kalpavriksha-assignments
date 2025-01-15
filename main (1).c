#include <stdio.h>
int main()
{
    int row;
    int column;
    scanf("%d", &row);
    scanf("%d", &column);
     int array[row][column];
     for(int i = 0; i < row; i++){
        for(int j =0; j < column; j++){
            scanf("%d", &array[i][j]);}
    }
    int transpose[row][column];
    for(int i = 0; i < row; i++){
        for(int j =0; j < column; j++){
          transpose[i][j] = array[j][i];
        }
    }
    for(int i = 0; i < row; i++){
        for(int j =0; j < column; j++){
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}
