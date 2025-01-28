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
Node* getTail(Node* curr){
    while(curr != NULL && curr->next != NULL){
        curr = curr->next;
    }
    return curr;
 }
Node* partition(Node* head, Node* tail){
     Node* pivot = head;
     Node* prev = head;
     Node* curr = head;
     while(curr != tail->next){
        if(curr->data < pivot->data){
            int temp = curr->data;
            curr->data = prev->next->data;
            prev->next->data = temp;
            prev = prev->next;
        }
        curr = curr->next;
     }
     int data = pivot->data;
     pivot->data = prev->data;
     prev->data = data;
     return prev;
 }
void quickSortHelper(Node* head, Node* tail){
    if(head == NULL || head == tail){
        return ;
    }
    Node* pivot = partition(head, tail);
    quickSortHelper(head, pivot);
    quickSortHelper(pivot->next, tail);
 }
 Node* quickSort(Node* head){
   Node* tail = getTail(head);
   quickSortHelper(head, tail);
   return head;
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
     head = quickSort(head);
     display(head);
     return 0;
 }