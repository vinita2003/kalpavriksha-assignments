#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
} Node;
Node* insertElement(Node*head, int value){
     Node* ptr = (Node*)malloc(sizeof(Node*));
     if(ptr == NULL){
        printf("NULL");
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
void display(Node *head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
 }
Node* sortedInsert(Node* createNode, Node* sorted){
    if(sorted == NULL  || sorted->data >= createNode->data ){
        createNode->next = sorted;
        sorted = createNode;  
    }
    else{
        Node* curr = sorted;
        while(curr->next != NULL && curr->next->data < createNode->data){
            curr = curr->next;
        }
        createNode->next = curr->next;
        curr->next = createNode;
        }
    return sorted;
     }
Node* insertionSort(Node* head){
    Node* sorted = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* next = curr->next;
        sorted = sortedInsert(curr, sorted);
        curr = next;
    }
    return sorted;
    }
int main(){
printf("enter the input");
    char input[100];
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';
    int indexInput = 0;
    int temp = 0;
    int is_negative = 0;
    Node* head = NULL;
    int flag = 0;
   while(indexInput <= strlen(input)){
        if(input[indexInput] == ' ' || input[indexInput] == '\0'){
            if(is_negative == 1){
                temp = temp*-1;
             head =  insertElement( head,temp);
            }else{
             head = insertElement(head,temp);
            }
            temp = 0;
           }
           else if(is_negative == '-'){
            is_negative  = 1;
           }else{
            temp = temp*10 + (input[indexInput] - '0');
           } 
           indexInput++;
    }
    display(head);
     printf("\n");
     head = insertionSort(head);
     display(head);
     return 0;
 }