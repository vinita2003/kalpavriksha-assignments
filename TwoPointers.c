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
void twoPointer(Node* head, int count, int target){
    int start = 0;
    int end = count-1;
    while(start < end){
        int newStart = start;
        int newEnd = end;
        Node* temp1 = head;
        Node* temp2 = head;
    while(newStart > 0){
            temp1 = temp1->next;
            newStart--;
        }
    while(newEnd > 0){
          temp2 = temp2->next;
          newEnd--;
        }
    if(temp1->data + temp2->data == target){
            printf("%d , %d" , temp1->data, temp2->data);
            return;
        }else if(temp1->data + temp2->data > target){
            --end;
        }else{
            ++start;
        }
    }
    printf("No such pair are exits");
    return;
 }
 int main(){
    printf("enter the input");
    char input[100];
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("enter the target");
    int target;
    scanf("%d", &target);
    getchar();
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
    int count = 0;
    Node* temp1 = head;
    while(temp1 != NULL){
        count++;
        temp1 = temp1->next;
    }
     twoPointer(head, count, target);
    return 0;
 }
