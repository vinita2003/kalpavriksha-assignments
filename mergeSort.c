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
Node* split(Node * head){
    Node* fast = head;
    Node* slow = head;
  while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if(fast != NULL){
          slow = slow->next;
        }
    }
   Node* temp = slow->next;
    slow->next = NULL;
    return temp;
   }
Node* merge(Node* first, Node* second){
     if(first == NULL){
        return second;
     }
     if(second == NULL){
        return first;
     }
   if(first->data < second->data){
        first->next = merge(first->next, second);
        return first;
     }else{
        second->next = merge(first, second->next);
        return second;
     }
   }
 Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
Node* second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
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
   head = mergeSort(head);
   display(head);
    return 0;
}