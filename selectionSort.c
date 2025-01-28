#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}Node;
Node* insertElement(Node *head, int value){
    Node*ptr = (Node*)malloc(sizeof(Node*));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        ptr->data = value;
        ptr->next = NULL;
        if(head == NULL){
            head = ptr;
        }else{
            Node*temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
    return head;
}
void display(Node *head){
     Node* temp = head;
     while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
     }
}
Node* selectionSort(Node* head, int size){
    int itr = 0;
    Node*temp = head;
    while(itr < size){
        Node*prev = temp;
        Node*temp1 = temp;
        Node*temp2 = temp1->next;
        while(temp2 != NULL){
            if(temp1->data > temp2->data){
                 temp1 = temp2;
            }
           temp2 =  temp2->next;
        }
     int data = prev->data;
     prev->data = temp1->data;
     temp1->data = data;
     temp = temp->next;
     itr++;
    }
    return head;
}
int main(){
    char input[200];
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = '\0';
    int inputIndex = 0;
    int temp = 0;
    int is_negative = 0;
    Node* head = NULL;
    while(inputIndex <= strlen(input)){
        if(input[inputIndex] == ' ' || input[inputIndex] == '\0'){
            if(is_negative){
                temp = temp*-1;
             head =  insertElement(head, temp);
               is_negative = 0;
            }else{
             head =  insertElement(head, temp);
            }
            temp = 0;
        }
        else if(input[inputIndex] == '-'){
            is_negative = 1;
        }else{
            temp = temp*10 + (input[inputIndex] - '0');
        }
        inputIndex++;
    }
    int count = 0;
    Node *temp1 = head;
     while(temp1 != NULL){
        temp1 = temp1->next;
        count++;
     }
   head = selectionSort(head,count);
    display(head);
    return 0;
}
