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
 void binarySearch(Node* head, int start, int end, int target){
    if(start > end){
        printf("-1");
        return;
    }
    int mid = (end+start)/2;
    int traverse = mid;
    Node* temp = head;
    while(traverse > 0){
        temp = temp->next;
        traverse--;
    }
    if(temp->data == target){
        mid = mid+1;
        printf("%d", mid);
        return;
    }else if(temp->data < target){
          binarySearch(head, mid+1, end, target);
    }else{
         binarySearch(head, start, mid-1, target);
    }
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
    binarySearch(head, 0 ,count-1, target);
    return 0;
    }