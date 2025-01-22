#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} Node;
Node *head;
void insertAtBeginning(int value){
      Node*ptr = (Node*)malloc(sizeof(Node*));
      if(ptr == NULL){
        printf("\n OverFlow\n");
      }else{
        ptr->data = value;
        ptr->next = head;
        head = ptr;}}
void insertAtEnd(int value){
    Node*ptr = (Node*)malloc(sizeof(Node*));
     Node*temp;
    if(ptr == NULL){
        printf("\n Overflow \n");
    }else{
        ptr->data = value;
        if(head == NULL){
           ptr->next = NULL;
            head = ptr;
          }else{
             temp = head;
            while(temp->next != NULL){
                temp = temp->next;}
           temp->next = ptr;
           ptr->next =NULL; } }}
void insertAtPosition(int position, int value){
    Node*ptr = (Node*)malloc(sizeof(Node*));
    Node* temp = head;
    int count = 0;
   while(temp != NULL){
          count++;
          temp = temp->next;
    }
   if(ptr == NULL){
        printf("\n Overflow\n");
    }else{
       if(count == 0){
            ptr->data = value;
            ptr->next = NULL;
            head = ptr;
            }
            else if(count+1 == position){
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
           ptr->data = value;
            temp->next = ptr;
           ptr->next =NULL;
          }else if(count+1 > position){
            temp = head;
            while(position -2 > 0){
                temp = temp->next;
                position--;
            }
            ptr->data = value;
            ptr->next = temp->next;
            temp->next = ptr;
          
             }else{
            printf("Invalid position\n");}}}
void display(){
      Node* temp = head;
      if(temp == NULL){
        printf("List is Empty");
      }else{
             while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
      }
      }
      printf("\n");}
void updateAtPosition(int position, int newValue){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
          count++;
          temp = temp->next;}
    if(count == 0){
           printf("Invalid\n");
            }else if(count >= position){
            temp = head;
            while(position -1 > 0){
                temp = temp->next;
                position--;
            }
            temp->data = newValue;}
            else{
            printf("Invalid position\n"); }}
    void deleteAtBeginning(){
      Node* temp;
     if(head == NULL){
           printf("Invalid\n");
      }else {
            temp = head;
            head = head->next;
            free(temp);}}
void deleteAtEnd(){
   Node* temp;
    if(head == NULL){
           printf("Invalid\n");
        }else if(head->next == NULL){
               temp = head;
               head = head->next;
               free(temp);
            }else{
                temp = head;
                 Node* temp1 = NULL;
            while(temp -> next != NULL){
                 temp1 = temp;
                temp = temp->next;}
           temp1->next = NULL;
           free(temp);}}
void deleteAtPosition(int position){
    Node* temp = head;
    int count = 0;
   while(temp != NULL){
          count++;
          temp = temp->next;}
   if(count == 0){
           printf("Invalid\n");
    }else if(position == 1){
             temp = head;
               head = head->next;
               free(temp);}
        else if(count  >= position){
            temp = head;
          Node* temp1 = head->next;
            while(position -2 > 0){
                temp = temp->next;
                temp1 = temp1->next;
                position--;
            }
           temp->next = temp1->next;
           free(temp1);
        }else{
            printf("invalid position\n");
        }}
int main(){
    int number_operation;
    int flag = 0;
    printf("The Number Of operation");
    scanf("%d", &number_operation);
    while(number_operation > 0 && (number_operation >= 1 && number_operation <= 100)){
        int choice;
        printf("Enter the number of choice");
        scanf("%d", &choice);
         if(choice < 1 || choice > 8){
            printf("Invalid Number of operation");
             flag = 1;
             break;
        }
        if(flag != 1){
            switch(choice){
            case 1:
            printf("Enter the value");
             int value;
            scanf("%d", &value);
            insertAtEnd(value);
            break;
            case 2:
            printf("Enter the value");
             int value1;
            scanf("%d", &value1);
            insertAtBeginning(value1);
            break;
            case 3: 
            printf("Enter the position and value");
            int position2, value2;
            scanf("%d %d", &position2, &value2);
            insertAtPosition(position2, value2);
            break;
            case 4:
            display();
            break;
            case 5:
            printf("Enter the position and value");
            int position3, newValue;
            scanf("%d %d", &position3, &newValue);
            updateAtPosition(position3, newValue);
            break;
           case 6:
            deleteAtBeginning();
            break;
            case 7:
            deleteAtEnd();
            break;
            case 8:
            printf("Enter the position");
            int position4;
            scanf("%d", &position4);
            deleteAtPosition(position4);
            break;
           default:
           break;}}
        number_operation--;}
        return 0;
}
