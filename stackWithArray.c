#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
typedef struct {
    int array[MAX_SIZE];
     int top;
}Stack;
void initalize(Stack *stack){
    stack->top = -1;
}
bool isFull(Stack *stack){
    return stack->top == MAX_SIZE - 1;
}
bool isEmpty(Stack *stack){
    return stack->top == -1;
}
void push(Stack* stack, int value){
    if(isFull(stack)){
        printf("Overflow");
        return;
    }
    stack->array[++stack->top] = value;
}
int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Underflow");
        return -1;
    }
    int value = stack->array[stack->top];
    stack->top--;
    return value;
}
int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Underflow");
        return 0;
    }
    return stack->array[stack->top];
}
int main(){
    Stack stack;
    initalize(&stack);
    int number_of_operation;
    scanf("%d", &number_of_operation);
    int choice;
    do{
        printf("Menu\n");
        printf("1. Push the value in array\n");
        printf("2. Pop the value from the array\n");
        printf("3. To retrive the peek the element of stack\n");
        printf("4. check the stack is full or not\n");
        printf("5. Check the stack is empty or not\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        printf("Enter the value");
        int value;
        scanf("%d", &value);
        push(&stack, value);
        break;
        case 2:
        printf("Ppped value");
        int r = pop(&stack);
        printf("%d", r);
        break;
        case 3:
        printf("peek element");
        int value2 = peek(&stack);
        printf("%d", value2);
        break;
        case 4:
        printf("full or not");
         bool value3 = isFull(&stack);
         if(value3){
           printf("empty is full");
         }else{
            printf("empty is not full");
         }
         break;
        case 5:
        printf("empty or not");
        bool value4 = isEmpty(&stack);
       if(value4){
        printf("empty");
       }else{
        printf("not empty");
       }
        break;
         default:
            break;
        }
       number_of_operation--;
    }while(number_of_operation > 0);
    return 0;
}