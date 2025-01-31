#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
typedef struct{
    int array[MAX_SIZE];
    int front;
    int rear;
}Queue;
void intialize(Queue *queue){
    queue->front = -1;
    queue->rear = -1;
}
bool isFull(Queue* queue){
    return queue->rear == MAX_SIZE - 1;
}
bool isEmpty(Queue* queue){
    return queue->front == -1;
}
int sizeofqueue(Queue* queue){
    int count = 0;
    for(int i = 0; i <= queue->rear; i++){
        count++;
    }
    return count;
}
void enqueue(Queue* queue, int value){
    if(isFull(queue)){
        printf("Queue is full");
        return;
    }
    if(isEmpty(queue)){
        queue->front = 0;
    }
    queue->array[++queue->rear] = value;
    printf("%d", value);
}
void dequeue(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty");
        return;
    }
    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }else{
        queue->front++;
    }
}
int peek(Queue* queue){
    return queue->array[queue->rear];
}
void display(Queue *queue){
    if(isEmpty(queue)){
      printf("Queue is empty\n");
    }
    for(int i = queue->front; i <= queue->rear; i++){
        printf("%d", queue->array[i]);
    }
    printf("\n");
}
int main(){
    Queue queue;
    intialize(&queue);
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
            case 2:
            dequeue(&queue);
            break;
            case 3:
            printf("peek value of queue");
            int peekvalue = peek(&queue);
            printf("%d", peekvalue);
            break;
            case 4:
            printf("The queue is empty or not\n");
            bool value4 = isEmpty(&queue);
            if(value4){
                printf("The queue is empty\n");
            }else{
                printf("The queue is not empty\n");
            }
            break;
            case 5:
            printf("The size of queue\n");
            int size = sizeofqueue(&queue);
            printf("%d", size);
            break;
            default:
            break;
}
        number_of_operation--;
    }while(number_of_operation > 0);
    return 0;
}