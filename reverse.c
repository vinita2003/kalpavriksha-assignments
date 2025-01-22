#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int data;
    struct Node *next;
} Node;
Node *head;
Node *head1;
void insertElement(int value){
     Node* ptr = (Node*)malloc(sizeof(Node));
     Node* temp;
     
     if(head == NULL){
         ptr->data = value;
         ptr->next = NULL;
         head = ptr;
     }else{
         ptr->data = value;
         temp = head;
         while(temp->next != NULL){
             temp = temp->next;
         }
         ptr->next = NULL;
         temp->next = ptr; }}
 void displayLinklist(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }}
Node* reverse(int count, Node* head){
    if(head != NULL){
        Node* prev=NULL;
        Node* temp=head;
        Node* temp1=head->next;
        Node* currentHead =head;
        for(int index=0;index<count-1 && temp1!=NULL;index++){
            temp->next=prev;
            prev=temp;
            temp=temp1;
            temp1=temp1->next;}
        temp->next=prev;
        head=temp;
        currentHead->next=temp1;
        if(temp1 != NULL){
            for(int index=0;index<count && temp1!=NULL;index++){
                prev=temp1;
                temp1=temp1->next;
            }
           if(prev != NULL)
                prev->next=reverse(count, prev->next);} }
          return head;
}
int main(){
char str[500];
    scanf("%499[^\n]%*c", str);
     int count;
    scanf("%d", &count);
    getchar();
    int index = 0;
    int temp = 0;
    int is_negative = 0;
    while(index < strlen(str)){
        if(str[index] != ' ' && str[index] != '-'){
            temp = temp*10 + (str[index]-'0');
        }
        else if(str[index] == '-'){
            is_negative = 1;
        }else{
            if(temp > 0){
                if(is_negative == 1){
                temp = temp*-1;
                    is_negative = 0;
                }
               insertElement(temp);
            temp = 0; 
            }}
        index++;}
    if(temp > 0){
         if(is_negative == 1){
                temp = temp*-1;
                    is_negative = 0;
                }
               insertElement(temp);
            temp = 0; }
   head = reverse(count, head);
   displayLinklist();
    return 0;
    }
