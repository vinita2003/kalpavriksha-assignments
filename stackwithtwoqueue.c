#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    int arr[MAX];
    int front, rear, size;

}Queue;
void initQueue(Queue* q){
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
int isEmptyQueue(Queue* q){
    return q->size == 0;
}
void enqueue(Queue* q, int value){
    if(q->size == MAX){
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear+1)%MAX;
    q->arr[q->rear] = value;
    q->size++;
}
int dequeue(Queue* q){
    if(isEmptyQueue(q)){
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->arr[q->front];
    q->front = (q->front +1)%MAX;
    q->size--;
    return val;
}
typedef struct{
    Queue q1, q2;
}Stack;
void initStack(Stack *s){
    initQueue(&s->q1);
    initQueue(&s->q2);
}
void push(Stack *s, int val){
    while(!isEmptyQueue(&s->q1)){
        enqueue(&s->q2, dequeue(&s->q1));
    }
    enqueue(&s->q1, val);
    while(!isEmptyQueue(&s->q2)){
        enqueue(&s->q1, dequeue(&s->q2));
    }
}
int pop(Stack *s){
    if(isEmptyQueue(&s->q1)){
        printf("Stack is empty");
        return -1;
    }
    return dequeue(&s->q1);
}
int peek(Stack *s){
   if(isEmptyQueue(&s->q1)){
        printf("Stack is empty");
        return -1;
    }
    return s->q1.arr[s->q1.front];

}
int isEmpty(Stack *s){
    return isEmptyQueue(&s->q1);
}
int sizeofstack(Stack *s){
    return s->q1.size;
}
int main(){
     Stack s;
     initStack(&s);
    int number_of_operation;
    printf("Enter the number of operation\n");
    scanf("%d", &number_of_operation);
    int choice;
    do{
        printf("Menu\n");
        printf("1. Add an element to the queue\n");
        printf("2. Remove the front element from the queue\n");
        printf("3. Retrive the front element without removing it\n");
        printf("4. Check if the queue is empty\n");
        printf("5. Return the number of elements in the queue\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the value\n");
            int value1;
            scanf("%d", &value1);
            push(&s, value1);
            break;
            case 2:
            printf("Popped value");
            int value = pop(&s);
            printf("%d", value);
            break;
            case 3:
            printf("Peek element of the queue\n");
           int peekValue = peek(&s);
           if(peekValue != -1){
           printf("%d", peekValue);
           }
           break;
           case 4:
            printf("Stack is empty or not\n");
            int value4 = isEmpty(&s);
            if(value4){
                printf("Stack is empty\n");
            }else{
                printf("Stack is not empty\n");
            }
            break;
            case 5:
            printf("Size of queue\n");
            int size = sizeofstack(&s);
            printf("%d", size);
            break;
            default:
            break;
        }
        number_of_operation--;
    }while(number_of_operation > 0);
    return 0;
}