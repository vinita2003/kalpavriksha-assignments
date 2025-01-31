#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}Node;
Node* push(Node* head, int value){
    Node* ptr = (Node*)malloc(sizeof(Node*));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        ptr->data = value;
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
        }else{
            ptr->next = head;
            head = ptr;
        }
    }
    return head;
}
Node* pop(Node* head){
    if(head == NULL){
        printf("Linklist is empty");
        return NULL;
    }else{
        head = head->next;
    }
    return head;
}
int peek(Node* head){
    if(head == NULL){
        printf("Linklist is Empty");
        return -1;
    }
    return head->data;
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
bool isEmpty(Node* head){
    if(head == NULL){
        return true;
    }
    return false;
}
int countlinklist(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
}
int main(){
    Node* head = NULL;
    int number_of_operation;
    printf("Enter the number of operation");
    scanf("%d", &number_of_operation);
    int choice;
    do{
        printf("Menu\n");
        printf("1. Enter the value for push in node\n");
        printf("2. Popped from the node value\n");
        printf("3. to retrive the peek element\n");
        printf("4. check linklist is empty or not");
        printf("5. count the size of linklist");
        printf("6. display the the element of linklist\n");
        printf("enter the choice\n");
        scanf("%d", &choice);
       switch(choice){
            case 1:
            printf("Enter the value\n");
            int value;
            scanf("%d", &value);
            head = push(head, value);
            break;
            case 2:
            printf("Popped from the linklist\n");
            head = pop(head);
            break;
            case 3:
            printf("Print the peek value of node\n");
            int value1 = peek(head);
            printf("%d", value1);
            break;
            case 4:
            printf("check the linklist is empty or not\n");
            bool value4 = isEmpty(head);
            if(value4){
                printf("Linklist is Empty\n");
            }else{
                printf("Linklist is not empty\n");
            }
            break;
            case 5:
            printf("Count the element in the linklist\n");
            int count = countlinklist(head);
            printf("%d", count);
            break;
             case 6:
            printf("Display the the element\n");
            display(head);
            break;
            default:
            break;
}
        number_of_operation--;
    }while(number_of_operation > 0);
    return 0;
}