#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}Node;
Node* enqueue(Node* head, int value){
    Node* ptr = (Node*)malloc(sizeof(Node));
    if(ptr == NULL){
        printf("Overflow\n");
    }else{
        ptr->data = value;
        ptr->next = NULL;
        if(head == NULL){
           head = ptr;
        }else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
    return head;
}
Node* dequeue(Node* head){
    if(head == NULL){
        printf("Queue is empty\n");
        return NULL;

    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    return head;
}
int peek(Node* head){
    if(head == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    return head->data;
}
bool isEmpty(Node* head){
    if(head == NULL){
        return true;
    }
    return false;
}
int sizeofqueue(Node* head){
    Node* temp  = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int main(){
    Node* head = NULL;
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
            head = enqueue(head, value1);
            break;
            case 2:
            head = dequeue(head);
            break;
            case 3:
            printf("Peek element of the queue\n");
           int peekValue = peek(head);
           printf("%d", peekValue);
            break;
            case 4:
            printf("Queue is empty or not\n");
            bool value4 = isEmpty(head);
            if(value4){
                printf("queue is empty\n");
            }else{
                printf("queue is not empty\n");
            }
            break;
            case 5:
            printf("Size of queue\n");
            int size = sizeofqueue(head);
            printf("%d", size);
            break;
            default:
            break;
        }
        number_of_operation--;
    }while(number_of_operation > 0);
    return 0;
}