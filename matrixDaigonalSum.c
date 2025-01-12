#include<stdio.h>

int main(){
    int size;
    scanf("%d", &size);

    // int columns;
    // scanf("%d", &columns);

    int array[size][size];

    for(int index1 = 0; index1 <size ; index1++){
        for(int index2 = 0; index2 < size; index2++){
            scanf("%d", &array[index1][index2]);
        }
    }
    int ans = 0;

    for(int index1 = 0; index1 < size; index1++){
        for(int index2 = 0; index2 < size; index2++){
            if(index1 == index2){
             ans += array[index1][index2];
            }
            if((index1 != index2)  && ((index1 + index2 ) == size-1)){
                ans += array[index1][index2];
            }
        }
    }

    printf("%d", ans);
    return 0;
}