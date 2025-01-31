#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef struct{
    int arr[MAX];
    int top;
}Stack;
void initStack(Stack *s){
    s->top = -1;
}
int isEmpty(Stack* s){
    return s->top == -1;
}
void push(Stack* s, int value){
    if(s->top == MAX - 1){
        printf("Queue is full");
        return;
    }
    s->arr[++s->top] = value;
}
int pop(Stack* s){
    if(isEmpty(s)){
      printf("Queue is empty\n");
      return -1;
    }
    return s->arr[s->top--];
}
typedef struct{
    Stack s1;
    Stack s2;
}Queue;
void initQueue(Queue *q){
    initStack(&q->s1);
    initStack(&q->s2);
}
void enqueue(Queue* q, int val){
    while(!isEmpty(&q->s1)){
        push(&q->s2, pop(&q->s1));
    }
    push(&q->s1, val);
    while(!isEmpty(&q->s2)){
        push(&q->s1, pop(&q->s2));
    }
}
int dequeue(Queue *q){
    if(isEmpty(&q->s1)){
      printf("Queue is empty\n");
      return -1;
    }
    return pop(&q->s1);
}
int front(Queue *q){
    if(isEmpty(&q->s1)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->s1.arr[q->s1.top];
}
int isEmptyQueue(Queue *q){
    return isEmpty(&q->s1);
}
int sizeofQueue(Queue *q){
    return q->s1.top +1;
}
int main(){
    Queue queue;
    initQueue(&queue);
    int number_of_operation;
    printf("Enter the number of operation\n");
    scanf("%d", &number_of_operation);
    int choice;
    do{
        printf("MENU\n");
        printf("1. Add an element to the queue\n");
        printf("2. Remove the front element from the queue.\n");
        printf("3. Retrive the front element without removing it\n");
        printf("4. Check if the queue is Empty\n");
        printf("5. Return the number of element in the queue\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the value\n");
            int value1;
            scanf("%d", &value1);
            enqueue(&queue, value1);
            break;
            case 2:{
            int value2 = dequeue(&queue);
            if(value2 != -1)
            printf("%d", value2);
            break;
            }
            case 3:{
            int peekvalue = front(&queue);
            if(peekvalue != -1)
            printf("%d", peekvalue);
            break;
            }
           case 4:{
            int value4 = isEmptyQueue(&queue);
            if(value4){
                printf("The queue is empty\n");
            }else{
                printf("The queue is not empty\n");
            }
            break;
            }
            case 5:
            printf("The size of queue\n");
            int size = sizeofQueue(&queue);
            printf("%d", size);
            break;
             default:
            printf("Invalid choice\n");
            break;
}
        number_of_operation--;
    }while(number_of_operation > 0);
    return 0;
}