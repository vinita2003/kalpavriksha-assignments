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
void linearSearch(Node* head, int target, int number_of_occurence){
   int array[number_of_occurence];
    int indexArray = 0;
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
      count++;
      if(temp->data == target){
        if(indexArray < number_of_occurence){
           array[indexArray++] = count;
        }
        }
        temp = temp->next;
    }
    if(indexArray == number_of_occurence){
        printf("%d", array[indexArray-1]);
    }
    else{
        printf("-1");
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
    printf("enter the n");
    int number_of_occurence;
    scanf("%d", &number_of_occurence);
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
    if(head == NULL){
        flag = 1;
    }
    if(flag != 1){
    linearSearch(head, target, number_of_occurence);
    }
    return 0;
}